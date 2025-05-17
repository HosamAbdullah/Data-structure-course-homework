#pragma once
#include <iostream>
#include <cassert>
using namespace std;

class Vector
{
	#pragma region Fields
	private: 
	  int size = 0;
	  int *arr = nullptr;
	  int Capacity = 0;
	#pragma endregion

	#pragma region Constructor
	public:
		Vector(int size):size(size)
		{
			if (size < 0)
				size = 1;
			Capacity = size + 10;
			arr = new int[Capacity] {};
		}
	#pragma endregion

	#pragma region Methods

	//problem 1
		void right_Rotate() {
			int lastElement = arr[size - 1];
			for (int i = size - 1; i > 0;--i) 
				arr[i] = arr[i-1];

			arr[0] = lastElement;
	}
	//problem 2
		void left_Rotate() {
			int firstElement = arr[0];
			for (int i = 0; i < size-1 ;++i)
				arr[i] = arr[i + 1];

			arr[size-1] = firstElement;
		}
	//problem 3
		void right_Rotate(int steps) {
			for (int i = 0; i < steps;++i)
				right_Rotate();
		}
	//problem 4
		int pop(int idx) {
			int deletedValue = arr[idx];
			int* arr2 = new int[size-1] {};
			int indexOfNewArray = 0;
			for (int i = 0; i < size;++i) {
				if (i == idx)
					continue;
				arr2[indexOfNewArray] = arr[i];
				indexOfNewArray += 1;
			}
			swap(arr, arr2);
			delete[]arr2;
			size--;
			return deletedValue;
		}

		//another solution
		int pop2(int idx) {
			int deletedValue = arr[idx];
			for (int i = idx; i < size;++i) 
				arr[i] = arr[i+1];
			size--;
			return deletedValue;
		}

	//problem 5

	int find_transposition(int value) {
		int position = -1;
		for(int i=0;i<size;++i)
			if (arr[i] == value) {
				position = i;
				if (i == 0)
					break;
				arr[i]= arr[i - 1];
				arr[i - 1] = value;	
				break;
			}
		return position;
	}

	//////////////////////helper functions/////////////////////

	void expand_capacity() {
		Capacity *= 2;
		int* arr2 = new int[Capacity] {};

		for (int i = 0; i < size; ++i)
			arr2[i] = arr[i];
		swap(arr, arr2);
		delete[] arr2;
	}

	void set(int idx, int val) {
		assert(0 <= idx && idx < size);
		arr[idx] = val;
	}

	void print() {
		for (int i = 0; i < size; ++i)
			cout << arr[i] << " ";
		cout << "\n";
	}
	#pragma endregion

};

