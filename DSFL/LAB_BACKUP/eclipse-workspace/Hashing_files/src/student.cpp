/*
 * student.cpp
 *
 *  Created on: 26-Mar-2018
 *      Author: e2007
 */
#include "student.h"
#include <iomanip>


void student :: create(student s[],int n)
{

	for(int i=0;i<n;i++)
	{
		cout<<"Enter Name of student  num. "<<i+1<<" : ";
		cin>>s[i].name;
		cout<<"\n";

		cout<<"Enter Phone number of student  num. "<<i+1<<" : ";
		cin>>s[i]. num;
		cout<<"\n"<<"\n";
	}
}

void student ::display(student arr[])
{
	cout<<setw(10)<<"Name"<<setw(15)<<"Phone  num."<<"\n";
	cout<<"---------------------------------------------------------------------";
	cout<<"\n";

	for(int i=0;i<10;i++)
		cout<<setw(10)<<arr[i].name<<setw(15)<<arr[i]. num<<"\n";

}

ll student::getnum()
{
	return num;
}

int student::getcount()
{
	return 0;
}

