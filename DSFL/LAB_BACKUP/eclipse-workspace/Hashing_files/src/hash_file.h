/*
 * hash_file.h
 *
 *  Created on: 26-Mar-2018
 *      Author: e2007
 */

#ifndef HASH_FILE_H_
#define HASH_FILE_H_

#include "student.h"

class hash_file {

	student data[100];
	int flag[100];
	int chain[100];
	int loc[100];
	int size;

public:
	hash_file();
	void updatesize();
	int hash(ll x);
	void insert(student);
	void display();
	int search(ll);
	int getsize();

};

#endif /* HASH_FILE_H_ */
