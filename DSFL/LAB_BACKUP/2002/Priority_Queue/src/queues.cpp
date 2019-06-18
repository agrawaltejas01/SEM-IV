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

int queues:: priority(int s)
{
	if(s==1 || s==2)
		return 1;

	else if(s==3 || s==4)
		return 2;

	else
		return 3;
}

void queues:: enqueue()
{
	node *n;
	n=new node;
	int ch;

	cout<<"Enter Name of Patient : ";
	cin>>n->name;
	cout<<endl;

	cout<<"Enter Address of Patient : ";
	cin>>n->add;
	cout<<endl;

	cout<<"Enter Phone Number of Patient : ";
	cin>>n->ph_no;
	cout<<endl;

	cout<<"Enter Disease of Patient : ";
	cout<<"\n\n\t1.Cancer\n\t2.Accident\n\t3.Blood Pressure\n\t4.Sugar\n\t5.Fever\n\t"
			"6.Cold\n\t";

	cout<<"Enter Option from Above Serviced Disease : ";
	cin>>ch;
	cout<<endl;

	switch (ch)
	{
		case 1 : n->dis="Cancer";
				 break;

		case 2 : n->dis="Accident";
				 break;

		case 3 : n->dis="BP";
				 break;

		case 4 : n->dis="Sugar";
				 break;

		case 5 : n->dis="Fever";
				 break;

		case 6 : n->dis="Cold";
				 break;

		default : cout<<"Choose From Disease Above\n";
				  break;

	}

	n->pri=priority(ch);

	cout<<endl;

	n->link=NULL;

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

	p=front;

	int min=5,count=0;

	while(p != NULL)
	{
		if(p->pri < min)
			min=p->pri;

		p=p->link;
	}

	//cout<<min<<endl;

	p=front;

	while(p != NULL)
	{
		if(p->pri==min)
			return count;

		else
			count++;

		p=p->link;
	}

}

void queues:: dequeue()
{
	int pos;

	pos=check(1);

	//cout<<""<<pos<<endl;

	node *p,*temp;

	p=front;
	temp=front;

	if(isempty())
	{
		cout<<"No Patient For Treatment\n";
		return;
	}

	else if(pos==0)
	{
		cout<<"Name : "<<front->name<<endl;
		cout<<"Address : "<<front->add<<endl;
		cout<<"Phone Number: "<<front->ph_no<<endl;

		front=front->link;
	}

	else
	{
		//cout<<"IGI\n";
		while(pos--)
		{
			temp=p;
			p=p->link;

		}

		temp->link=p->link;

		cout<<"Name : "<<p->name<<endl;
		cout<<"Address : "<<p->add<<endl;
		cout<<"Phone Number: "<<p->ph_no<<endl;

		delete p;
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

	p=front;

	while(p != NULL)
	{
		cout<<"Name 	    : "<<p->name<<endl;
		cout<<"Address 	 : "<<p->add<<endl;
		cout<<"Phone Number : "<<p->ph_no<<endl;
		cout<<"Disease		: "<<p->dis<<endl<<endl;

		p=p->link;
	}

	cout<<endl;
}
