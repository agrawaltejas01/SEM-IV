
                              //STACK.cpp

/*
 * stacks.cpp
 *
 *  Created on: 27-Dec-2017
 *      Author: e2002
 */

#include "stack.h"
#include<malloc.h>
#include<iostream>
#include <stdexcept>
using namespace std;

stacks::stacks()
{
	Top=NULL;
}

int stacks:: isempty()
{
	if( Top==NULL)
		return 1;

	else
		return 0;
}

int stacks:: isfull()
{
	int count=0;
	node *p;

	p=Top;

	while(p!=NULL)
	{
		count++;
		p=p->link;
	}

	if(count==max)
		return 1;

	else
		return 0;
}

void stacks:: push(int x)
{
	if(!isfull())
	{
		node *n;

		n=(node*)malloc(sizeof(node));

		n->data=x;
		n->link=Top;

		Top=n;
	}

	else
	{
		cout<<"stacks is Full!!\n";
		return ;
	}
}

char stacks:: tope()
{
	if(!isempty())
		return Top->data;

	else
	{
				return ' ' ;
	}
}

char stacks :: pop()
{
	if(!isempty())
	{
		int n;
		n=Top->data;

		Top=Top->link;

		return n;
	}

	else
		return ' ';
}
