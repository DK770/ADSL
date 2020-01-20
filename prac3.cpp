//============================================================================
// Name        : prac3.cpp
// Author      : dhruv kanekal
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//Create inorder threaded binary tree and perform inorder, preorder traversal.

#include<iostream>
using namespace std;

class node
{
	node* llink;
	node* rlink;
    bool rbit;
    bool lbit;
	int data;
	friend class tree;
};

class tree
{
	node* root;
    void maketree(node*,bool);
    void inorder();
    node* insuc(node*);
	void preorder();
	node* presuc(node*);
public:
    tree()
	{
        root=new node;
        root->data=-1;
        root->lbit=0;
        root->rbit=1;
        root->llink=root->rlink=root;
    }
	void create();
	void inorder_traverse()
	{
		inorder();
	}
	void preorder_traverse()
	{
		preorder();
	}
};

void tree::create()
{
	cout<<"Enter data for tree:-\n";
	maketree(root,0);
}

void tree::maketree(node* father,bool dir)
{
	char ch;
	node* temp=new node;
	temp->lbit=0;
	temp->rbit=0;
	cout<<"Enter data:\t";
	cin>>temp->data;
	if(dir==0){
		temp->llink=father->llink;
		temp->rlink=father;
		father->lbit=1;
		father->llink=temp;
	}
	else{
		temp->rlink=father->rlink;
		temp->llink=father;
		father->rbit=1;
		father->rlink=temp;
	}
	cout<<"Do you want to Enter left child of "<<temp->data<<"(y/n)?:\t";
	cin>>ch;
	if(ch=='y' || ch=='Y'){
		maketree(temp,0);
	}
	cout<<"Do you want to Enter right child of "<<temp->data<<"(y/n)?:\t";
	cin>>ch;
	if(ch=='y' || ch=='Y'){
		maketree(temp,1);
	}
}

node* tree::insuc(node *t)
{
	if(t->rbit==0)
		return t->rlink;
	t=t->rlink;
	while(t->lbit==1)
		t=t->llink;
	return t;
}

void tree::inorder()
{
	node* t=root->llink;
	while(t->lbit==1)
		t=t->llink;
	while(t!=root){
		cout<<t->data<<" ";
		t=insuc(t);
	}
}

node* tree::presuc(node* t)
{
	if(t->lbit==1)
		return t->llink;
	while(t->rbit==0 && t->rlink!=root)
		t=t->rlink;
	return t->rlink;
}

void tree::preorder()
{
	node* t=root->llink;
	while(t!=root){
		cout<<t->data<<" ";
		t=presuc(t);
	}
}

int main()
{
	tree t;
	t.create();
	cout<<endl;
	cout<<"The inorder representation of the tree is:\t";
	t.inorder_traverse();
	cout<<endl;
	cout<<"The preorder representation of the tree is:\t";
	t.preorder_traverse();
	cout<<endl;
	return 0;
}
