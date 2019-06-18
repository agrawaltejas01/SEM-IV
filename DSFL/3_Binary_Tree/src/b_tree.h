
                        //B_TREE.h


/*
 * b_tree.h
 *
 *  Created on: 15-Jan-2018
 *      Author: e2002
 */

#ifndef B_TREE_H_
#define B_TREE_H_

struct node
{
	node *left;
	node *right;

	int data;
};

class b_tree
{
	node * root;
	public:
			node* create();
			node* display_leaf(node *);
			int height(node *);
			void display(node *);
			void display_level(node *);
			node *copy_tree(node *);
};

#endif /* B_TREE_H_ */
