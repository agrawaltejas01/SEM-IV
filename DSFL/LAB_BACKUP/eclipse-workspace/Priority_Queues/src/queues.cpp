/*
 * queues.cpp
 *
 *  Created on: 08-Jan-2018
 *      Author: e2002
 */

#include "queues.h"
#include<iostream>
#include<malloc.h>
#include<string>
#include<iomanip>
#include"patient.h"
using namespace std;

queues::queues()
{
	front=rear=NULL;
}

int queues:: isfull()
{
	node *p;
	int count;
	p=front;
	while(p != NULL)
	{
		p=p->link;
		count++;
	}

	if(count==max)
			return 1;
	else
			return 0;

}

int queues:: isempty()
{
	if(rear==NULL)
		return 1;

	else
		return 0;

}

/*int //queues:: priority(int s)
int  priority(int s)
{
	if(s==1 || s==2)
		return 1;

	else if(s==3 || s==4)
		return 2;

	else
		return 3;
}*/




void queues:: enqueue()
{
	node *n;
	patient pt;
	//n=getdata();
	n=pt.getdata();
	if(isempty())
		front=rear=n;

	else
	{
		rear->link=n;
		rear=n;
	}
}

int queues::check(int temp)
{
	node *p;

	int min=5;

	p=front;

	while(p != NULL)
	{
		if(p->pri < min)
			min=p->pri;
		p=p->link;
	}
	return min;
}

void queues:: dequeue()
{

	if(isempty())
		{
			cout<<"No Patient For Treatment\n";
			return;
		}

	int min_pri;

	min_pri=check(1);
	node *current,*previous;

	current=front;

	if(front->pri==min_pri)
	{
		cout<<"Name : "<<front->name<<endl;
		cout<<"Address : "<<front->add<<endl;
		cout<<"Phone Number: "<<front->ph_no<<endl;
		cout<<"Disease : "<<front->dis<<endl;
		cout<<"Priority : "<<front->pri<<endl;

		if(front==rear)
			front=rear=NULL;


		else
			front=front->link;
	}

	else
	{
		while( (current->pri != min_pri) && (current->link != NULL) )
		{
			previous=current;
			current=current->link;
		}

		cout<<"Name : "<<current->name<<endl;
		cout<<"Address : "<<current->add<<endl;
		cout<<"Phone Number: "<<current->ph_no<<endl;
		cout<<"Disease : "<<current->dis<<endl;
		cout<<"Priority : "<<current->pri<<endl;

		if(current==rear)
		{
			rear=previous;
			rear->link=NULL;
			delete current;
		}

		else
		{
			previous->link=current->link;
			delete current;
		}
	}
}

void queues:: display()
{
	if(isempty())
	{
		cout<<"No Patient For Treatment\n";
		return;
	}

	node *p;

	//cout<<left;

	cout<<setw(24)<<"NAME    "
		<<setw(20)<<"ADDRESS "
		<<setw(20)<<"PHONE NO"
		<<setw(20)<<"DISEASE "
		<<setw(20)<<"PRIORITY"<<endl;

	cout<<"-----------------------------------------------------------------";
	cout<<"-----------------------------------------------------------------";
	cout<<"-----------------------------------------------------------------"<<endl;

	p=front;

	while(p != NULL)
	{
		//cout<<left;
		cout<<setw(15)<<"        "<<p->name;
		cout<<setw(15)<<"        "<<p->add;
		cout<<setw(15)<<"        "<<p->ph_no;
		cout<<setw(15)<<"        "<<p->dis;
		cout<<setw(15)<<"        "<<p->pri<<endl<<endl;

		p=p->link;
	}

	cout<<endl;
}
