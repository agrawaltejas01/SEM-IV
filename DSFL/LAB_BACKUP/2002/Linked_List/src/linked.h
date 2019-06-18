/*
 * linked.h
 *
 *  Created on: 20-Dec-2017
 *      Author: e2002
 */

#ifndef LINKED_H_
#define LINKED_H_

typedef struct node
{
	int data;
	struct node *link;
}node;

class linked {
public:
		node * create(int n);

		void display(node *p);
		node * del(int n,node *p,int val);
		node * insert(int n,node *p,int val,int pos);
};

#endif /* LINKED_H_ */
