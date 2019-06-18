/*
 * linked.cpp
 *
 *  Created on: 20-Dec-2017
 *      Author: e2002
 */

#include "linked.h"
#include<malloc.h>
#include<iostream>
using namespace std;

node * linked:: create(int n)
{
	node *head,*p,*q;

	head = (node *)malloc(sizeof(node));

	cout<<"Enter Element no. 1 : ";
	cin>>head->data;
	cout<<endl;

	head->link=NULL;

	p=head;

	for(int i=1;i<n;i++)
	{
				q=(node *)malloc(sizeof(node));

		cout<<"Enter Element no. "<<i+1<<" : ";
		cin>>q->data;
		cout<<endl;

		q->link=NULL;

		p->link=q;
		p=q;

	}

	return head;

}

void linked :: display(node *p)
{
	//cout<<"IGI\n";
	node *head;

	head=p;

	while(head != NULL)
	{
		cout<<""<<head->data<<"->";
		head=head->link;
	}

	cout<<"NULL";
	cout<<endl;
}
node * linked :: del(int n,node *head,int val)
{
	node *p,*temp;

	p=head;

	if(p->data == val)
		return p->link;

	else
	{
		while(p != NULL && p->data != val)
		{	temp=p;
			p=p->link;
		}

		if(p == NULL)
		{
			cout<"No Entries !!!\n";
			return head;
		}

		else if(p->data == val)
		{
			temp->link = p->link;
			return head;
		}
	}


}

node * linked :: insert(int n,node *head,int val,int pos)
{
	node *p,*q;

	q=(node *)malloc(sizeof(node));
	q->data=val;
	q->link=NULL;

	if(pos == 0)
	{
		q->link = head;
		return q;
	}

	else if(pos >= n)
	{
		p=head;

		while(p->link != NULL)
			p=p->link;

		p->link=q;

		return head;
	}

	else
	{
		p=head;

		while(--pos)
			p=p->link;

		q->link=p->link;
		p->link=q;
		return head;
	}
}

