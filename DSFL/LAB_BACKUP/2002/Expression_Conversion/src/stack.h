/*
 * stacks.h
 *
 *  Created on: 27-Dec-2017
 *      Author: e2002
 */

#ifndef stacks_H_
#define stacks_H_

#include <stdexcept>
#include <stdexcept>

typedef struct node
{
		char data;
		struct node *link;
}node;

//using node= node<T>

class stacks
{
	int max=50;
	node *Top;

public:
	stacks();

	int isempty();
	int isfull();

	void push(int x);
	char tope();
	char pop();

};

#endif /* stacks_H_ */
