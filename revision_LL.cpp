//============================================================================
// Name        : revision_LL.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct node
{
	node* prev;
	char name[20];
	int rollno;
	node* next;
};

class linkedlist
{
public:
	node* head;
	linkedlist()
	{
		head=NULL;
	}
	void display()
	{
		cout<<"\nLinked List:-\n";
		node *t=head;
		while (t)
		{
			cout<<t->rollno<<"\t"<<t->name<<endl;
			t=t->next;
		}
		cout<<"linked List over.\n";
		count();
	}
	void add_first(node*);
	void add_last();
	void remove_first();
	void remove_last();
	void count();
	void reverse(linkedlist);
};

void linkedlist::add_first(node* ptr)
{
/*  node* ptr;
	ptr=new node;
	cout<<"enter details:\t";
	cin>>ptr->rollno>>ptr->name; */
	ptr->next=head;
	ptr->prev=NULL;
	head=ptr;
}

void linkedlist::add_last()
{
	node *ptr;
	ptr=new node;
	cout<<"enter details:\t";
	cin>>ptr->rollno>>ptr->name;
	node *t=head;
	while (t->next!=NULL)
		t=t->next;
	t->next=ptr;
	ptr->prev=t;
	ptr->next=NULL;
}

void linkedlist::remove_first()
{
	node* ptr=head;
	head=ptr->next;
	head->prev=NULL;
	delete ptr;
	ptr=NULL;
}

void linkedlist::remove_last()
{
	node* ptr=head;
	node* t;
	while(ptr->next->next!=NULL)
		ptr=ptr->next;
	t=ptr->next;
	ptr->next=NULL;
	t->prev=NULL;
	delete t;
	t=NULL;
}

void linkedlist::count()
{
	int cntr=0;
	node* t=head;
	while (t)
	{
		cntr++;
		t=t->next;
	}
	cout<<"No.of elements = "<<cntr<<endl;
}

void linkedlist::reverse(linkedlist L1)
{
	node *ptr1, *ptr2;
	ptr1=L1.head;
	while(ptr1->next!=NULL)
	{
		ptr2=ptr1;
		if(!this->head)
		{
			head=ptr2;
		}
		else
		{
			head->prev=ptr2;
			ptr2->next=head;
			head=ptr2;
		}
		ptr1=ptr1->next;
	}
	cout<<"Reverse over.\n";
}

int main()
{
	linkedlist LL1,LL2;
	cout<<"Add three elements from the front:\n";
	for(int i=0;i<3;i++)
	{
		node* ptr;
		ptr=new node;
		cout<<"enter details:\t";
		cin>>ptr->rollno>>ptr->name;
		LL1.add_first(ptr);

	}
//	LL1.add_first();
//	LL1.add_first();
	LL1.display();

	cout<<"Add three elements from the back:\n";
	LL1.add_last();
	LL1.add_last();
	LL1.add_last();
	LL1.display();

	cout<<"Remove one element from the front:\n";
	LL1.remove_first();
	LL1.display();
	cout<<"Remove one element from the back:\n";
	LL1.remove_last();
	LL1.display();

	LL2.reverse(LL1);
	LL2.display();

	cout<<"\ndone.\n";
	return 0;
}
