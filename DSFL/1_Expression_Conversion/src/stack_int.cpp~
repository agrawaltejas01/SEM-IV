

                              //STACK_INT.cpp
                              
/*
 * stack_int.cpp
 *
 *  Created on: 01-Jan-2018
 *      Author: e2002
 */

#include "stack_int.h"
#include<malloc.h>
#include<iostream>
#include <stdexcept>
using namespace std;

stack_int::stack_int()
{
	Top=NULL;
}

int stack_int:: isempty()
{
	if( Top==NULL)
		return 1;

	else
		return 0;
}

int stack_int:: isfull()
{
	int count=0;
	node1 *p;

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

void stack_int:: push(int x)
{
	if(!isfull())
	{
		node1 *n;

		n=(node1*)malloc(sizeof(node1));

		n->data=x;
		n->link=Top;

		Top=n;
	}

	else
	{
		cout<<"Stack is Full!!\n";
		return ;
	}
}

int stack_int:: tope()
{
	if(!isempty())
		return Top->data;

	else
			return -999;
}

int stack_int:: pop()
{
	if(!isempty())
	{
		int n;
		n=Top->data;

		Top=Top->link;

		return n;
	}

	else
				return -999;
}


