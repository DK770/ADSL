//============================================================================
// Name        : prac4.cpp
// Author      : dhruv kanekal
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/* There are flight paths between cities. If there is a flight between city A
and city B then there is an edge between the cities. The cost of the edge can
be the time that flight takes to reach city B from A, or the amount of fuel
used for the journey. Represent this as a graph. The node can be represented
by airport name or name of the city. Use adjacency list representation of the
graph. (Operation to be performed adding and deleting edge, adding and
deleting vertices, calculated in-degree and out-degree for directed graph. Use
any traversal to traverse graph) */

#include<iostream>
#include<string.h>
using namespace std;

class node
{
    string city;
    int w;
    node* next;
    friend class graph;
};

class graph
{
    int vertices;
    node* head[20];
    string entry[20];
public:
    graph(int n)
	{
        vertices=n;
        for(int i=0;i<20;i++)
        	head[i]=NULL;
    }
    void addentry(string s,int n)
    {
        entry[n]=s;
    }
    void print()
    {
		cout<<"Source\t\t\t Destination\t\t Time required\n";
        for(int i=0;i<vertices;i++){
			if(head[i]!=NULL){
				node* p=head[i];
				cout<<p->city;
				p=p->next;
				while(p!=NULL){
					/*if(p!=head[i]->next)
						cout<<"\t\t\t";
					else
						cout<<"\t\t";*/
					cout<<"\t\t\t"<<p->city<<"\t\t\t"<<p->w<<"\n";
					p=p->next;
				}
				if(p==NULL)
					cout<<"\n";
			}
        }
    }
    int getindex(string s)
    {
    	for(int i=0;i<vertices;i++)
    	{
    		if(entry[i]==s)
    			return i;
    	}
    	return -1;
    }
    void create();
    void addcity();
    void deletecity();
    void addpath();
    void deletepath();
    void calculate();
};

void graph::create()
{
    for(int i=0;i<vertices;i++){
        int no;
        node *p,*temp;
        head[i]=new node;
        head[i]->w=0;
        cout<<"Enter the name of city "<<i+1<<"\t";
        cin>>head[i]->city;
        addentry(head[i]->city,i);
        p=head[i];
        cout<<"Enter No of cities having path from "<<head[i]->city<<"\t";
        cin>>no;
        if(no==0)
            head[i]->next=NULL;
        else
        {
            for (int j=0;j<no;j++)
            {
                temp=new node;
                cout<<"Enter city "<<j+1<<" from "<<head[i]->city<<"\t";
                cin>>temp->city;
                cout<<"Enter time required to reach that city\t";
                cin>>temp->w;
                p->next=temp;
                temp->next=NULL;
                p=p->next;
            }
        }
        cout<<"\n";
    }
}

void graph::addcity()
{
	int no;
	node *p,*temp;
	vertices++;
	head[vertices-1]=new node;
	head[vertices-1]->w=0;
	cout<<"Enter name of new city\t";
	cin>>head[vertices-1]->city;
	addentry(head[vertices-1]->city,vertices-1);
    cout<<"Enter No of cities having path from "<<head[vertices-1]->city<<"\t";
    cin>>no;
    p=head[vertices-1];
    if(no==0)
		p->next=NULL;
	else
	{
		for (int j=0;j<no;j++)
		{
			temp=new node;
			cout<<"Enter city "<<j+1<<" from "<<head[vertices-1]->city<<"\t";
			cin>>temp->city;
			cout<<"Enter time required to reach that city\t";
			cin>>temp->w;
			p->next=temp;
			temp->next=NULL;
			p=p->next;
		}
		cout<<"\n";
	}
}

void graph::deletecity()
{
	string c;
	int index;
	node *p,*t;
	cout<<"Enter the city you want to delete\t";
	cin>>c;
	index=getindex(c);
	if(index==-1)
	{
		cout<<"Invalid";
		return;
	}
	entry[index]="none";
	for(int i=0;i<vertices;i++)
	{
		if(head[i]->city==c)
		{
			head[i]=NULL;
		}
		else
		{
			p=head[i];
			t=head[i];
			while(p!=NULL)
			{
				if(p->city==c)
				{
					while(t->next!=p)
					{
						t=t->next;
					}
					t->next=p->next;
					p->next=NULL;
					delete p;
					break;
				}
				p=p->next;
			}
		}
	}
}

void graph::addpath()
{
	string c;
	node *p,*temp;
	int index;
	cout<<"Adding a path to the list:-\n";
	cout<<"Enter source city\t";
	cin>>c;
	index=getindex(c);
	if(index==-1)
	{
		cout<<"Invalid";
		return;
	}
	temp=new node;
	cout<<"Enter destination city\t";
	cin>>temp->city;
	cout<<"Enter time required to reach that city\t";
	cin>>temp->w;p=head[index];
	temp->next=NULL;
	p=head[index];
	while(p->next!=NULL)
		p=p->next;
	p->next=temp;
}

void graph::deletepath()
{
	string c,d;
	node *p,*t;
	int index;
	cout<<"Deleting a path from the list:-\n";
	cout<<"Enter source city\t";
	cin>>c;
	index=getindex(c);
	if(index==-1)
	{
		cout<<"Invalid";
		return;
	}
	cout<<"Enter destination city\t";
	cin>>d;
	p=head[index];
	t=head[index];
	while(p!=NULL)
	{
		if(p->city==d)
		{
			while(t->next!=p)
				t=t->next;
			t->next=p->next;
			p->next=NULL;
			delete p;
			break;
		}
		p=p->next;
	}
}

void graph::calculate()
{
	int count;
	int in[vertices],out[vertices];
	for(int i=0;i<vertices;i++)
	{              //memset
		in[i]=0;out[i]=0;
	}
    for(int i=0;i<vertices;i++)
    {
		if(head[i]!=NULL)
		{
			count=0;
			node* p=head[i]->next;
			while(p!=NULL)
			{
				in[getindex(p->city)]++;
				count++;
				p=p->next;
			}
			out[getindex(head[i]->city)]=count;
			cout<<"\n";
		}
    }
    for(int i=0;i<vertices;i++)
    {
    	if(head[i]!=NULL){
    		cout<<"In degree of "<<head[i]->city<<" is "<<in[i]<<endl;
    		cout<<"Out degree of "<<head[i]->city<<" is "<<out[i]<<endl;
    	}
    }
}

int main()
{
    int n;
    cout<<"Enter No. of cities in graph\t";
    cin>>n;
    graph g(n);
    g.create();
    g.print();

    g.addcity();
    g.print();

    g.deletecity();
    g.print();

    g.addpath();
    g.print();

    g.deletepath();
    g.print();

    g.calculate();
    return 0;
}
