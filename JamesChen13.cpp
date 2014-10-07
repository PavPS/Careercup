#include "stdafx.h"

/*
Two numbers are missing from the first hundred numbers. They are NOT sorted. How to find them?
You can't sort.. and can't iterate one by one.. has to be less than O(N)? Can't use stack , set or any collection interface or in fact any other data structure or array!
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

double fact(unsigned count)
{
	if (count <= 1)
		return 1;

	return count * fact(count - 1);
}

void JamesChen13()
{
	const auto ArraySize = 10;
	cout << "        ";
	vector<int> values;
	for (unsigned i = 0; i < ArraySize; ++i)
	{
		values.push_back(i+1);
		cout << "#" << setfill('0') << setw(2) << i << " ";
	}
	cout << endl;

	values.erase(values.begin() + rand() % values.size());
	values.erase(values.begin() + rand() % values.size());

	cout.fill(' ');

	cout << "values: ";
	for (const auto& v : values)
		cout << " " << setw(2) << v << " ";
	cout << endl;

	/* KINDERGARTEN SOLUTION */
	/*
	x + y = a
	x * y = b

	x = a - y
	(a - y) * y = b
	a * y - y ^ 2 - b = 0
	y ^ 2 - a * y + b = 0
	A = 1
	B = -a
	C = b
	x+ = -B + (B ^ 2 - 4 * A * C)^ 0.5 / (2 * A)
	x- = -B - (B ^ 2 - 4 * A * C)^ 0.5 / (2 * A)
	*/

	double sum = 0, mul = 1;
	for (const auto& v : values)
	{
		sum += v;
		mul *= v;
	}

	sum = ArraySize * (ArraySize + 1) / 2 - sum;
	mul = fact(ArraySize) / mul;

	const auto A = 1;
	const auto B = -sum;
	const auto C = mul;
	const auto D = (B * B - 4 * A * C);
	const auto SqrD = pow(D, 0.5);

	const auto x1 = (-B + SqrD) / (2 * A);
	const auto x2 = (-B - SqrD) / (2 * A);

	double root1;
	if (x1 >= 1 && x1 <= ArraySize)
		root1 = x1;
	else
		root1 = x2;

	const auto root2 = sum - root1;

	cout << "Missing numbers are: (" << round(root1) << "; " << round(root2) << ")" << endl;
}