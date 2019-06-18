/*
 * BST.h
 *
 *  Created on: 12-Feb-2018
 *      Author: e2002
 */

#ifndef BST_H_
#define BST_H_

struct node
{
	int data;
	node * right;
	node * left;
};

class BST
{
public :

	BST();
	node * root;
	void create(int val);
	node* search(node *,int val);
	node* mirror(node *);
	void display_level(node *);
	void display(node *);
	int height(node *);
	node* Delete(node *,int);
};

#endif /* BST_H_ */
