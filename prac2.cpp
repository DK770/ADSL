//============================================================================
// Name        : prac2.cpp
// Author      : dhruv kanekal
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//A Dictionary stores keywords & its meanings. Provide facility for adding new
//keywords, deleting keywords, updating values of any entry, assign a given tree
//into another tree (=). Provide facility to display whole data sorted in ascending/
//Descending order. Also find how many maximum comparisons may require for
//finding any keyword. Use Binary Search Tree for implementation.

#include <iostream>
#include<string.h>
using namespace std;

class node
{
	node* lchild;
	node* rchild;
	string word;
	string meaning;
	friend class bst;
public:
	node()
	{
		word="";
		meaning="";
		lchild=NULL;
		rchild=NULL;
	}
	node(string s,string m)
	{
		word=s;
		meaning=m;
		lchild=NULL;
		rchild=NULL;
	}
};

class bst
{
	node* root;
public:
	bst()
	{
		root=NULL;
	}
	void add(string,string);
	node* insert(node*,string,string);
	void show();
	void display(node*);
	void del();
	node* remove(node*,string);
	void change();
	node* update(node*,string);
	void showDesc();
	void displayDesc(node*);
	void find();
	node* cmp(node*,string);
};

void bst::add(string s,string m)
{
	root=insert(root,s,m);
}

void bst::show()
{
	if(root!=NULL)
		display(root);
	else
		cout<<"Tree is Empty.\n";
}

void bst::display(node* r)
{
	if(r!=NULL)
	{
		display(r->lchild);
		cout<<r->word<<" = "<<r->meaning<<endl;
		display(r->rchild);
	}
}

void bst::showDesc()
{
	if(root!=NULL)
		displayDesc(root);
	else
		cout<<"Tree is Empty.\n";
}

void bst::displayDesc(node* r)
{
	if(r!=NULL)
	{
		displayDesc(r->rchild);
		cout<<r->word<<" = "<<r->meaning<<endl;
		displayDesc(r->lchild);
	}
}

node* bst::insert(node* r,string s,string m)
{
	if(r==NULL)
		return new node(s,m);
	else if(r->word==s)
	{
		cout<<"Duplicate DATA\n";
		return NULL;
	}
	else if(r->word>s)
	{
		r->lchild=insert(r->lchild,s,m);
		return r;
	}
	else if(r->word<s)
	{
		r->rchild=insert(r->rchild,s,m);
		return r;
	}
	return NULL;
}

void bst::del()
{
	string s;
	cout<<"Enter the keyword you want to delete:\t";
	cin>>s;
	root=remove(root,s);
}

node* bst::remove(node* r, string s)
{
	if(r==NULL)
		return r;
	else if(r->word>s)
	{
		r->lchild=remove(r->lchild,s);
		return r;
	}
	else if(r->word<s)
	{
		r->rchild=remove(r->rchild,s);
		return r;
	}
	else
	{
		node* temp;
		if(r->lchild==NULL)
		{
			temp=r;
			r=r->rchild;
			delete temp;
			return r;
		}
		else if(r->rchild==NULL)
		{
			temp=r;
			r=r->lchild;
			delete temp;
			return r;
		}
		else
		{
			temp=root->lchild;
			while(temp->rchild!=NULL)
				temp=temp->rchild;
			r->word=temp->word;
			r->meaning=temp->meaning;
			r->lchild=remove(r->lchild,temp->word);
		}
	}
	return NULL;
}

void bst::change()
{
	string s;
	cout<<"Enter keyword to change:\t";
	cin>>s;
	root=update(root,s);
}

node* bst::update(node* r, string s)
{
	if(r==NULL)
		return r;
	else if(r->word>s)
	{
		r->lchild=update(r->lchild,s);
		return r;
	}
	else if(r->word<s)
	{
		r->rchild=update(r->rchild,s);
		return r;
	}
	else if(r->word==s)
	{
		cout<<"Enter updated meaning of "<<r->word<<":\t";
		cin.ignore();
		getline(cin,r->meaning);
		return r;
	}
	else
	{
		cout<<"Match not found.\n";
	}
	return NULL;
}

void bst::find()
{
	string s;
	cout<<"Enter keyword you want to find:\t";
	cin>>s;
	root=cmp(root,s);
}

node* bst::cmp(node* r,string s)
{
	static int count=0;
	if(r==NULL)
		return r;
	else if(r->word>s)
	{
		count++;
		r->lchild=cmp(r->lchild,s);
		return r;
	}
	else if(r->word<s)
	{
		count++;
		r->rchild=cmp(r->rchild,s);
		return r;
	}
	else if(r->word==s)
	{
		cout<<"Keyword is present and "<<count<<" comparisons required to find it.\n";
		return r;
	}
	else
	{
		cout<<"Match not found.\n";
	}
	return NULL;
}

int main()
{
	bst b;
	cout<<"Enter words and their meanings to create a dictionary.\n";
	cout<<"Enter esc to exit i.e stop entering.\n";
	string s,m;
	do
	{
		cout<<"Enter keyword:\t";
		getline(cin,s);
		if(s!="esc")
		{
			cout<<"Enter its meaning:\t";
			getline(cin,m);
			b.add(s,m);
		}
	}while(s!="esc");

	cout<<"The dictionary is:-\n";
	b.show();
	cout<<endl;
	b.del();
	cout<<"The updated dictionary is:-\n";
	b.show();
	cout<<endl;
	b.change();
	b.show();
	b.find();
	cout<<endl;
	cout<<"The dictionary in descending order is:-\n";
	b.showDesc();
	return 0;
}
