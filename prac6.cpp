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
public:
	word()
	{
		key="\0";
		value="\0";
	}
	friend class dictionary;
};

class dictionary
{
	word w[26][2];
public:
	void input();
	void output();
	int hashfunc(char);
};

void dictionary::input()
{
	int a,addr=0;
	cout<<"Number of words in dictionary?:\t";
	cin>>a;
	for(int i=0;i<a;i++)
	{
		string s,s1;
		cout<<"Enter keyword no. "<<i+1<<":-\t";
		cin>>s;
		addr=hashfunc(s[0]);
		if(w[addr][0].key=="\0")
		{
			w[addr][0].key=s;
			cout<<"Enter meaning of above keyword:-\t";
			cin>>w[addr][0].value;
		}
		else if(w[addr][1].key=="\0")
		{
			w[addr][1].key=s;
			cout<<"Enter meaning of above keyword:-\t";
			cin>>w[addr][1].value;
		}
		else
		{
			int flg=1;
			while(flg)
			{
				if (addr==25)
					addr=0;
				addr++;
				if(w[addr][0].key=="\0")
				{
					w[addr][0].key=s;
					cout<<"Enter meaning of above keyword:-\t";
					cin>>w[addr][0].value;
					flg=0;
				}
				else if(w[addr][1].key=="\0")
				{
					w[addr][1].key=s;
					cout<<"Enter meaning of above keyword:-\t";
					cin>>w[addr][1].value;
					flg=0;
				}
			}
		}
	}
}

int dictionary::hashfunc(char c)
{
	int i;
	i=c;
	if(i>64 && i<96)
		i=i+32;
	i=i%97;
	cout<<i<<endl;
	return i;
}

int main() {
	dictionary d1;
	d1.input();
	//d1.output();
	return 0;
}
