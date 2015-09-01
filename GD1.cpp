#include "stdafx.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class CFoo
{
public:
    CFoo()
    {
        cout << "ctor";
    }
};

void GD1()
{
    auto *arr = new string[2];
    
    arr[0] = "123";
    arr[0] += "123";
    
    cout << arr[0];
    
    delete[] arr;
}

#if !defined(_MSC_VER)
int main()
{
        GD1();
        return 0;
}
#endif