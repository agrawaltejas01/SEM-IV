/*
 * no_replace.h
 *
 *  Created on: 18-Mar-2018
 *      Author: deception
 */

#ifndef NO_REPLACE_H_
#define NO_REPLACE_H_
#include"student.h"

class no_replace
{
	student data[20];
	int flag[20];
	int chain[20];

	int size;

public:
	no_replace();				//send size of student array
	int hash(long long int);

	void insert(student s[],int);
	void search(long long int);
	void display();
};

#endif /* NO_REPLACE_H_ */
