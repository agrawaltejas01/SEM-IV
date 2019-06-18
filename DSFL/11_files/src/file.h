/*
 * file.h
 *
 *  Created on: 11-Apr-2018
 *      Author: hp
 */

#ifndef FILE_H_
#define FILE_H_
#include<fstream>
using namespace std;

struct student{
	int rollno;
	char name[20];
};
class file {
	fstream of;
public:

	file();
	void create(int);
	void add();
	void display();
	int search(int );
	void delete_record(int);
	virtual ~file();
};

#endif /* FILE_H_ */
