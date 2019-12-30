//============================================================================
// Name        : prac1.cpp
// Author      : dhruv kanekal
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//
//Given binary tree with n nodes and perform following operations on it.
//a) Assign this tree to another [operator=] *
//b) Erase all nodes in a binary tree *
//c) Create a mirror image of the tree *
//d) Check two binary trees are equal or not *
//e) Inorder, Preorder, Postorder traversal of tree(recursive and non-recursive) *
//f) Print internal and leaf nodes *

#include <iostream>
using namespace std;

class node
{
	node *lchild,*rchild;
	int data;
public:
	node()
	{
		lchild=NULL;
		rchild=NULL;
		data=0;
	}
	friend class tree;
};

class tree
{
	node *root;
	node* stack[50];
	node* maketree();
	void erasetree(node*);
	void inorder(node*);
	void preorder(node*);
	void postorder(node*);
	void nonrecpre(node*);
	void nonrecin(node*);
	void nonrecpost(node*);
	void swap(node*);
	void postleaf(node*);
	void postinternal(node*);
	int check(node*,node*);
	void copy(node*, node*);

public:
	tree()
	{
		root=NULL;
	}
	void create()
	{
		root=maketree();
		cout<<"Binary tree entered.\n";
	}
	void treedelete()
	{
//		char pass[10];
//		cout<<"Enter password to delete-\t";
//		cin>>pass;
//		if(pass=="tree")
		{
			erasetree(root);
			cout<<"\nTree deleted successfully.\n";
		}
//		else
//			cout<<"Command denied.\n";
	}
	void display()
	{
		cout<<"\nBy recursive method-";
		cout<<"\nPreorder form:-\n";
		preorder(root);
		cout<<"\nInorder form:-\n";
		inorder(root);
		cout<<"\nPostorder form:-\n";
		postorder(root);
		cout<<"\nBy non-recursive method-";
		cout<<"\nPreorder form:-\n";
		nonrecpre(root);
		cout<<"\nInorder form:-\n";
		nonrecin(root);
		cout<<"\nPostorder form:-\n";
		nonrecpost(root);
	}
	void leafnode()
	{
		cout<<"\nLeaf nodes are:-\n";
		postleaf(root);
	}
	void mirror()
	{
		swap(root);
		cout<<"\nTree has been swapped."<<endl;
		display();
	}
	void internalnode()
	{
		cout<<"\nInternal nodes are:-\n";
		postinternal(root);
	}
	void checkcall(tree t1)
	{
		int i;
		i=check(this->root,t1.root);
		if(i)
			cout<<"\nThe given binary trees are not equal.\n";
		else
			cout<<"\nThe given binary trees are equal.\n";
	}
	void operator =(tree);

};

int tree::check(node *t,node *t1)
{
	if(!t && !t1)
		return 0;
	if(t->data!=t1->data)
		return 1;
	return (check(t->rchild,t1->rchild) + check(t->lchild,t1->lchild));
}

void tree::swap(node* T)
{
	if(T==NULL)
		return;
	if(T!=NULL)
	{
		swap(T->lchild);
		swap(T->rchild);
		node* temp;
		temp=T->lchild;
		T->lchild=T->rchild;
		T->rchild=temp;
	}
}

node* tree::maketree()
{
	node* temp;
	char ch;
	temp=new node;
	temp->lchild=NULL;
	temp->rchild=NULL;
	cout<<"Enter data:-\t";
	cin>>temp->data;
	cout<<"Enter left child of "<<temp->data<<" ?(y/n)\t";
	cin>>ch;
	if(ch=='y')
		temp->lchild=maketree();
	cout<<"Enter right child of "<<temp->data<<" ?(y/n)\t";
	cin>>ch;
	if(ch=='y')
		temp->rchild=maketree();
	cout<<"Level entered.\n";
	return temp;
}

void tree::erasetree(node *t)
{
	if(t!=NULL)
	{
		erasetree(t->lchild);
		erasetree(t->rchild);
		delete t;
		t=NULL;
	}
}

void tree::inorder(node *t)
{
	if(t!=NULL)
	{
		inorder(t->lchild);
		cout<<t->data<<"  ";
		inorder(t->rchild);
	}
}

void tree::preorder(node *t)
{
	if(t!=NULL)
	{
		cout<<t->data<<"  ";
		preorder(t->lchild);
		preorder(t->rchild);
	}
}

void tree::postorder(node *t)
{
	if(t!=NULL)
	{
		postorder(t->lchild);
		postorder(t->rchild);
		cout<<t->data<<"  ";
	}
}

void tree::nonrecpre(node* t)
{
	int i=0;
	while(1)
	{
		while(t!=NULL)
		{
			cout<<t->data<<"  ";
			if(t->rchild!=NULL)
			{
				i=i+1;
				stack[i]=t->rchild;
			}
			t=t->lchild;
		}
		if(i==0)
			return;
		t=stack[i];
		i=i-1;
	}
}

void tree::nonrecin(node* t)
{
	int i=0;
	while(1)
	{
		while(t!=NULL)
		{
			i=i+1;
			if(i>50)
			{
				cout<<"Stack is full.\n";
				break;
			}
			stack[i]=t;
			t=t->lchild;
		}
		if(i==0)
			return;
		t=stack[i];
		i=i-1;
		cout<<t->data<<"  ";
		t=t->rchild;
	}
}

void tree::nonrecpost(node* t)
{
	int i=0;
	while(1)
	{
		while(t!=NULL)
		{
			i=i+1;
			stack[i]=t;
			if(t->rchild!=NULL)
			{
				i=i+1;
				stack[i]=t->rchild;
				i++;
				stack[i]=NULL;
			}
			t=t->lchild;
		}
		if(i==0)
			return;
		while(stack[i]!=NULL)
		{
			t=stack[i];
			cout<<t->data<<"  ";
			i=i-1;
		}
		if(i!=0)
			i=i-1;
		if(i==0)
			return;
		t=stack[i];
		i=i-1;
	}
}

void tree::postleaf(node *t)
{
	if(t!=NULL)
	{
		postleaf(t->lchild);
		postleaf(t->rchild);
		if(t->rchild==NULL && t->lchild==NULL)
			cout<<t->data<<"  ";
	}
}

void tree::postinternal(node *t)
{
	if(t!=NULL)
		{
			postleaf(t->lchild);
			postleaf(t->rchild);
			if(t->rchild==NULL || t->lchild==NULL)
				cout<<t->data<<"  ";
		}
}

void tree::operator =(tree t)
{
	cout<<"\nCopying tree to other object ...\n";
	root=new node;
	copy(root,t.root);
	cout<<"Copy over.\n";
}

void tree::copy(node *cpy, node *orig)
{
	cpy->data=orig->data;
	if(orig->lchild)
	{
		cpy->lchild=new node;
		cpy->lchild->data=orig->lchild->data;
		copy(cpy->lchild, orig->lchild);
	}
	if(orig->rchild)
	{
		cpy->rchild=new node;
		cpy->rchild->data=orig->rchild->data;
		copy(cpy->rchild, orig->rchild);
	}
	return;
}

void menu()
{
	cout<<"1.Display Menu."<<endl;
	cout<<"2.Create Binary Tree."<<endl;
	cout<<"3.Display Binary Tree."<<endl;
	cout<<"4.Copy Tree into Another Variable"<<endl;
	cout<<"5.Display Internal Nodes."<<endl;
	cout<<"6.Display Leaf Nodes."<<endl;
	cout<<"7.Create Mirror Image of Binary Tree."<<endl;
	cout<<"8.Check If 2 Binary Trees Are Equal."<<endl;
	cout<<"9.Delete Tree."<<endl;
	cout<<"10.exit."<<endl;
}

int main()
{
	tree T1,T2,T3;
	int choice;
	cout<<"\tMENU:-\n";
	menu();
	do
	{
		switch(choice)
		{
			case 1:
				menu();
				break;
			case 2:
				T1.create();
				break;
			case 3:
				T1.display();
				break;
			case 4:
				T2=T1;
				T2.display();
				break;
			case 5:
				T2.internalnode();
				break;
			case 6:
				T2.leafnode();
				break;
			case 7:
				T2.mirror();
				break;
			case 8:
				T1.checkcall(T2);
				break;
			case 9:
				T1.treedelete();
				break;
			case 10:
				cout<<"\tThank You.\n";
				break;
		}
	}while(choice!=10);
	return 0;
}
