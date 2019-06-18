/*
 * adj_list.h
 *
 *  Created on: 21-Feb-2018
 *      Author: e2002
 */
#include<iostream>
#include<string>
using namespace std;


struct frnd
{
	string name;
	frnd * next;

};

struct node
{
	string Name;
	int dd,mm,yy;
	int post;
	node * down;
	frnd * Next;
	int visited;
	int friends;
};

#ifndef ADJ_LIST_H_
#define ADJ_LIST_H_

class adj_list
{

public:

		node * root;

		int max;
		int min;
		int same_month;
		int max_friends;
		string popular;
		string social;
		string introvert;

		adj_list();
		node * create(int);
		frnd * add_friend(node *);
		void display(node *);

		void dfs(node *,int);
		void bfs(node *);
		node * search(string);
		void unvisit();
};

#endif /* ADJ_LIST_H_ */
