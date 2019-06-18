/*
 * student.h
 *
 *  Created on: 26-Mar-2018
 *      Author: e2007
 */

#ifndef STUDENT_H_
#define STUDENT_H_
#include<iostream>
#include<string>
#define ll long long
using namespace std;

class student
{

public:

		string name;
		ll num;

		ll getnum();
		int getcount();
		void create(student data[],int n);
		void display(student data[]);
};

#endif /* STUDENT_H_ */
