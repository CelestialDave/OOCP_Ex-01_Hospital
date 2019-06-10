#ifndef __ARRAY_H
#define __ARRAY_H
#include <iostream>
using namespace std;
#include <string>


template <class T>
class Array
{
private:
	int physicSize, logicSize;
	string delimeter;
	T** arr;
public:


Array operator=(const Array& other)
{
	int i;
	for (i = 0; i<this->logicSize; i++)
		delete arr[i];
	delete[]arr;
	this->logicSize = other.logicSize;
	this->physicSize = other.physicSize;

	for (i = 0; i < logicSize; i++)
	{
		this->arr[i] = other.arr[i];
	}
	delete[]other.arr;
	return *this;
}

T* operator[](int index) const
{
	return arr[index];
}

int getlogicSize() const
{
	return logicSize;
}

~Array()
{
	for (int i = 0; i < logicSize; i++)
		delete arr[i];
	delete[]arr;
}

void addToArray(T& toAdd)
{
	alloc();//to reallocte the array to the new size
	arr[logicSize] = &toAdd;
	logicSize++;
}

Array(string delimiter=" ") :arr(nullptr)
{
	physicSize = 0;
	logicSize = 0;
	this->delimeter = delimiter;
}

void alloc()
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


};

#endif // !__ARRAY_H
