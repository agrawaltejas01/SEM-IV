/*
 * student.h
 *
 *  Created on: 18-Mar-2018
 *      Author: deception
 */

#ifndef STUDENT_H_
#define STUDENT_H_
#include<iostream>
#include<string>
using namespace std;

class student
{

public:
		int n;
		string name;
			long long int no;
		void create(student data[]);
		void display(student data[]);
};

#endif /* STUDENT_H_ */
