/*
 * queues.h
 *
 *  Created on: 08-Jan-2018
 *      Author: e2002
 */

#ifndef QUEUES_H_
#define QUEUES_H_

#include<iostream>
#include<malloc.h>
#include<string>
using namespace std;

struct node
{
	string name;
		string add;
		string ph_no;
		string dis;
	int pri;

	node *link;
};

class queues
{
	node *front,*rear;

	int max=50;

	public:
		queues();
		int isfull();
		int isempty();
		int check(int temp);
		//int priority(int s);
		node *getdata();
		void enqueue();
		void dequeue();
		void display();


};

#endif /* QUEUES_H_ */
