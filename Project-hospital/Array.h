#ifndef __ARRAY_H
#define __ARRAY_H
#include <iostream>
using namespace std;


template <class T>
class Array
{
private:
	int physicSize, logicSize;
	char delimeter;
	T** arr;
public:

Array(char delimiter);
void alloc();
void addToArray(T& toAdd);
~Array();

};

template<class T>
Array::~Array()
{
	for (int i = 0; i < logicSize; i++)
		delete arr[i];
	delete[]arr;
}

template<class T>
void Array::addToArray(T& toAdd)
{
	alloc();//to reallocte the array to the new size
	arr[logicSize] = toAdd;
	logicSize++;
}

template<class T>
Array::Array(char delimiter) :arr(nullptr)
{
	physicSize = 0;
	logicSize = 0;
	this->delimeter = delimiter;
}

template<class T>
void Array::alloc()
{
	if (physicSize == 0) // If this is the 1st Department
	{
		arr = new T*;
		physicSize++;
		return;
	}
	else if (logicSize == physicSize) //if there is no place in the array
	{
		physicSize *= 2;
		T** newArr = new T*[physicSize];
		for (int i = 0; i < logicSize; i++)
		{
			newArr[i] = arr[i];
		}
		delete[] arr;
		arr = newArr;
		return;
	}
	else
		return;
}


#endif // !__ARRAY_H
