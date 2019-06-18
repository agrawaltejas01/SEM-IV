/*
 * tree.h
 *
 *  Created on: 29-Jan-2018
 *      Author: e2002
 */

#include<string>
#include<stack>
using namespace std;

#ifndef TREE_H_
#define TREE_H_

struct node
{
	node *left;
	node *right;

	char data;
};

class tree
{

	public:
			node * root;
			node *  create(char x);

			void construct_tree_postorder(string str);
			void construct_tree_preorder(string str);

			void inorder(node* );
			void preorder(node* );
			void postorder(node* );

			void inorder_non_recurs(node *);
			void preorder_non_recurs(node *);
			void postrder_non_recurs(node *);
};

#endif /* TREE_H_ */
