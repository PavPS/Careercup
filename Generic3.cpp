#include "stdafx.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <atomic>
#include <assert.h>
#include <string>

using namespace std;

template<class T>
class MySmartPtr
{
public:
	static MySmartPtr create(const T& value)
	{
		auto cb = new ControlBlock();
		cb->Counter = 0;
		cb->Object = value;

		return MySmartPtr<T>(cb);
	}

	~MySmartPtr()
	{
		Release();
	}

	T const* operator->() const
	{
		return &cb_->Object;
	}

	const T& operator*() const
	{
		return cb_->Object;
	}

	MySmartPtr(const MySmartPtr<T>& ptr)
		:cb_(ptr.cb_)
	{
		Acquire();
	}

	const int RefCount() const
	{
		return cb_->Counter.load();
	}

	const MySmartPtr<T>& operator=(const MySmartPtr<T>& ptr)
	{
		if (this == &ptr)
			return *this;

		Release();

		cb_ = ptr.cb_;
		Acquire();

		return *this;
	}

private:
	struct ControlBlock
	{
		T Object;
		atomic<int> Counter;
	};

	MySmartPtr(ControlBlock *cb)
		:cb_(cb)
	{
		Acquire();
	}

	ControlBlock *cb_;

	void Acquire()
	{
		const auto was = cb_->Counter++;
		if (was == numeric_limits<int>::max())
			throw runtime_error("too many owners");
	}

	void Release()
	{
		auto decremented = --cb_->Counter;
		if (decremented < 0)
			throw runtime_error("wrong count owners");

		if (!decremented)
		{
			cout << "Release()" << endl;
			delete cb_;
		}
	}
};

void Generic3()
{
	int value = 10;
	auto smart1 = MySmartPtr<int>::create(value);
	auto smart2 = smart1;

	int value2 = 100;
	auto smart3 = MySmartPtr<int>::create(value2);

	cout << "smart1 is: " << *smart1 << ", ref count = " << smart1.RefCount() << endl;
	cout << "smart2 is: " << *smart2 << ", ref count = " << smart2.RefCount() << endl;
	cout << "smart3 is: " << *smart3 << ", ref count = " << smart3.RefCount() << endl;

	smart3 = smart2;

	cout << "smart1 is: " << *smart1 << ", ref count = " << smart1.RefCount() << endl;
	cout << "smart2 is: " << *smart2 << ", ref count = " << smart2.RefCount() << endl;
	cout << "smart3 is: " << *smart3 << ", ref count = " << smart3.RefCount() << endl;

	auto smart4 = MySmartPtr<string>::create("text");
	cout << "smart4 is: " << *smart4 << ", ref count = " << smart4.RefCount() << ", size = " << smart4->size() << endl;
}