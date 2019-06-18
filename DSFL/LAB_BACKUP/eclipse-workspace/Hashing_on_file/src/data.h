/*
 * data.h
 *
 *  Created on: 26-Mar-2018
 *      Author: e2002
 */

#ifndef DATA_H_
#define DATA_H_
#include<string>
using namespace std;

struct record
{
	string Name;
	int id;
	int loc;
	int link;
};

class data
{
	int rec;
	record arr[20];
	int flag[20];
	int chain[20];

public:
	void init();
	void display();
	void write();
	void insert();
	int hash(int);

};

#endif /* DATA_H_ */