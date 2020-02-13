//============================================================================
// Name        : prac6.cpp
// Author      : dhruv kanekal
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*Implement all the functions of a dictionary (ADT) using hashing. Data: Set of
(key, value) pairs, Keys are mapped to values, Keys must be comparable, Keys
must be unique Standard Operations: Insert(key, value), Find(key), Delete(key)
(Use linear probing with and without replacement. Calculate the average search
cost for both.) */

#include <iostream>
using namespace std;

class word
{
	string key,value;
	friend class dictionary;
};

class dictionary
{

};

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
