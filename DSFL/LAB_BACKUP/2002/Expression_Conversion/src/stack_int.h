/*
 * stack_int.h
 *
 *  Created on: 01-Jan-2018
 *      Author: e2002
 */

#ifndef STACK_INT_H_
#define STACK_INT_H_

typedef struct node1
{
		int data;
		struct node1 *link;
}node1;

class stack_int
{

	int max=50;
		node1 *Top;

	public:
		stack_int();

		int isempty();
		int isfull();

		void push(int x);
		int tope();
		int pop();
};

#endif /* STACK_INT_H_ */
