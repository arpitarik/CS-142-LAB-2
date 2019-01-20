#include<iostream>
using namespace std;

class Node 
{
	public:
	Node *next;
	Node *previous;
	int data;
	Node()
	{
		next=NULL;
		previous=NULL;
	}
};

class dlinklist
{
	Node *head;
	Node *tail;
	public:
	doublelinklist()
	{
		head=NULL;
		tail=NULL;
	}
	void insert(int value);
	void insertat(int pos,int value);
	void del();
	void delat(int pos);
	int count();
	void display();
};

void doublelinklist::insert(int value)
{
	Node *pointer=new Node;
	pointer->data=value;
	if (head==NULL)
	{head=ptr;}
	else
	{pointer->previous=tail;
	 tail->next=pointer;}
	tail=pointer;
}

void doublelinklist::insertat(int pos,int value)
{
	if( pos>this->count() )
	cout<<"Linklist doesnot have this many elements"<<endl;
	else
	{
	Node *temp=new Node;
	temp->data=value;
	if (pos==1)
	{
		head->previous=temp;
		temp->next=head;
		temp->previous=NULL;
		head=temp;
	}
	else
	{	
		int i=1;
		Node *pointer=head;
		while(i<pos-1)
		{pointer=pointer->next;i++;}
		temp->previous=pointer;
		temp->next=pointer->next;
		pointer->next=temp;
		if(temp->next!=NULL)
		temp->next->previous=temp;
	}
	}
}

void doublelinklist::del()
{
	Node *pointer=head;
	while(pointer->next!=tail)
	{pointer=pointer->next;}
	tail=pointer;
	pointer=pointer->next;
	tail->next=NULL;
	pointer->previous=NULL;
	delete pointer;
}

void doublelinklist::delat(int pos)
{
	if( pos>this->count() )
	cout<<"the Linklist does not have the required no.of elements"<<endl;
	else
	{
		Node *pointer=head;int i=1;
		while(i<pos)
		{pointer=pointer->next;i++;}
		
		if (pointer!=head)
		{pointer->previous->next=pointer->next;}
		
		if (pointer!=tail)
		{pointer->next->previous=pointer->previous;}
		
		pointer->next=NULL;
		pointer->previous=NULL;
		delete pointer;
		
	}
	
	
}

int doublelinklist::count()
{
	Node *pointer=head;int i=0;
	while(pointer!=NULL)
	{
		i+=1;
		pointer=pointer->next;
	}
	return i;
}

void doublelinklist::display()
{
	Node *pointer=head;
	while(pointer!=NULL)
	{
		cout<<pointer->data<<"->";
		pointer=pointer->next;
	}
	cout<<"NULL"<<endl;
}

int main()
{
	doublelinklist dl;
	dl.insert(1);dl.insert(2);dl.insert(3);dl.insert(4);dl.insert(5);
	dl.display();
	dl.insertat(3,7);
	dl.display();
	dl.insertat(9,9);
	dl.del();
	dl.display();
	dl.delat(3);dl.display();	
	return 0;
}

    
