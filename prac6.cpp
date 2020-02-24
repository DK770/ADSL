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
	void inputrepl();
	void output();
	int hashfunc(char);
	void insert();
	void insertrepl();
	void deleteentry();
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
				else
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

void dictionary::output()
{
	int i;
	for(i=0;i<26;i++)
	{
		if(w[i][0].key!=" ")
			cout<<"\n"<<w[i][0].key<<" - "<<w[i][0].value;
		if(w[i][1].key!=" ")
			cout<<"\n"<<w[i][1].key<<" - "<<w[i][1].value;
		cout<<endl;
	}
}

void dictionary::deleteentry()
{
	string s;
	cout<<"\nEnter the keyword which is to be deleted:-\t";
	cin>>s;
	int add=hashfunc(s[0]);
	do
	{
		if(w[add][0].key==s)
		{
			w[add][0].key="\0";
			w[add][0].value="\0";
			return;
		}
		if(w[add][1].key==s)
		{
			w[add][0].key="\0";
			w[add][0].value="\0";
			return;
		}
		add++;
		if(add==25)
			add=0;
		}
		while(add!=hashfunc(s[0]));
}

int main() {
	dictionary d1;
	d1.input();
	d1.output();
	return 0;

	/* dictionary d;
	int ch;
	cout<<"\nEnter \n0 to exit\n1 for input without replacement\n2 for input with replacement\n3 for output \n4 for insert without replacement \n5 for insert with replacement \n6 for search\n7 for delete";
	do
	{
		cout<<"\nEnter your choice ";
		cin>>ch;
		switch(ch)
		{
		case 1:
			d.input();
			break;
		case 2:
			d.winput();
			break;
		case 3:
			d.output();
			break;
		case 4:
			d.insert();
			break;
		case 5:
			d.winsert();
			break;
		case 6:
			d.search();
			break;
		case 7:
			d.deletee();
			break;
		}
	}
	while(ch); */

}
