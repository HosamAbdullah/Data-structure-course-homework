// vector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Vector.h"

int main()
{
	int n = 5;
	Vector v(n);
	for (int i = 0; i < n; ++i)
		v.set(i, i);
	// 0 1 2 3 4 
	
#pragma region Test proplem 1 =>"right rotation"
	v.print();
	cout << "************After Right Rotation*************************\n";
	v.right_Rotate();
	v.print();
#pragma endregion

#pragma region Test proplem 2 =>"left rotation"
	v.print();
	cout << "************After ledt Rotation*************************\n";
	v.left_Rotate();
	v.print();
#pragma endregion

#pragma region Test proplem 3 =>"right rotation with steps"
	v.print();
	cout << "************After Right Rotation with steps*************************\n";
	v.right_Rotate(2);
	v.print();
#pragma endregion

#pragma region Test proplem 4 =>"delete a position"
	v.print();
	cout << "************After delete *************************\n";
	cout << v.pop2(2);
	cout << "\n";
	v.print();
#pragma endregion

#pragma region Test proplem 5 =>"improved search"
	v.print();
	cout << "************After search *************************\n";
	cout << v.find_transposition(0);
	cout << "\n";
	v.print();
	cout << "************After search *************************\n";
	cout << v.find_transposition(0);
	cout << "\n";
	v.print();
#pragma endregion

}
