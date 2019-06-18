/*
 * replace.h
 *
 *  Created on: 18-Mar-2018
 *      Author: deception
 */

#ifndef REPLACE_H_
#define REPLACE_H_
#include"student.h"

class replace
{
	student data[20];
	int flag[20];
	int chain[20];

	int size;

public:
	replace();				//send size of student array
	int hash(long long int);

	void insert(student s[],int);
	void search(long long int);
	void display();
};

#endif /* REPLACE_H_ */
