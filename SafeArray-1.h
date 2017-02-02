#pragma once
#include <iostream>
#include <cstdlib>									// Sara Savitz
using namespace std;								// U37713110
													// COP4530.001F16
template <class T>
class SafeArray
{

public:
 SafeArray<T> (int firstInvalidIndex);
 SafeArray<T> (int firstValidIndex, int firstInvalidIndex);
 T& operator[](int ndx);
 int length() const;
 SafeArray<T> (const SafeArray<T>& firstArray);			// Copy Constructor declaration
 SafeArray& operator=(const SafeArray<T>& firstArray);	// Assignment operator declaration
 ~SafeArray();

 private:
 int firstValid;
 int firstInvalid;
 T *A;
};


// Constructor implementation 
template <class T>

SafeArray<T>::SafeArray(int firstInvalidIndex) :
firstValid(0), firstInvalid(firstInvalidIndex)

{
	A = new T[firstInvalid];
}



// Overloaded constructor implementation 
template <class T>

SafeArray<T>::SafeArray(int firstValidIndex, int firstInvalidIndex) :
firstValid(firstValidIndex), firstInvalid(firstInvalidIndex)

{
	A = new T[firstInvalid - firstValid];
}



// Operator[] implementation; checks if index is within bounds
template <class T>

T& SafeArray<T>::operator[](int ndx)
{
	if(ndx > firstInvalid - 1)
	{
		cout << "Safe Array index " << ndx << " out of bounds: too large" << endl;
		exit(1);
	}

	if(ndx < firstValid - 1)
	{
		cout << "Safe Array index " << ndx << " out of bounds: too small" << endl;
		exit(1);
	}
		
		return this->A[ndx - firstValid];

}



// Length function implementation; returns length of SafeArray object
template <class T>

int SafeArray<T>::length() const
{
	return firstInvalid - firstValid;
}



// Copy constructor implementation; performs deep copy of SafeArray object
template <class T>

SafeArray<T>::SafeArray(const SafeArray<T>& otherArray)
{
	A = new T[otherArray.length()];			// Dynamically create array of same length 
	firstInvalid = otherArray.firstInvalid;	// Assign member variables to new object
	firstValid = otherArray.firstValid;

	// Copy contents of old array into new array
	for(int i = 0; i < otherArray.length(); ++i)
	{
		A[i] = otherArray.A[i];
	}

}



// Assignment operator implementation
template <class T>

SafeArray<T>& SafeArray<T>::operator=(const SafeArray<T>& otherArray)
{	
	
	if(this == &otherArray)		// Checks if arrays are equivalent
		return *this;

	else
	{
		delete [] A;


		firstValid = otherArray.firstValid;			
		firstInvalid = otherArray.firstInvalid;	
		A = new T[firstInvalid - firstValid];	// Assigns member variables to new object

		for(int i = 0; i < otherArray.length(); ++i)
		{

			this->A[i] = otherArray.A[i];	
		}


		return *this;
	}


}

// Destructor implementation
	template <class T>

	SafeArray<T>::~SafeArray()
	{
		delete [] A;
	}