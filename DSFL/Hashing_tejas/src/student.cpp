/*
 * student.cpp
 *
 *  Created on: 18-Mar-2018
 *      Author: deception
 */

#include "student.h"
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

void student :: create(student arr[])
{
	cout<<"Enter number of students : ";
	cin>>n;
	cout<<endl;

	for(int i=0;i<n;i++)
	{
		cout<<"Enter Name of student no. "<<i+1<<" : ";
		cin>>arr[i].name;
		cout<<endl;

		cout<<"Enter Phone numeber of student no. "<<i+1<<" : ";
		cin>>arr[i].no;
		cout<<endl<<endl;
	}
}

void student ::display(student arr[])
{
	cout<<setw(10)<<"Name"<<setw(15)<<"Phone no."<<endl;
	cout<<"---------------------------------------------------------------------";
	cout<<endl;

	for(int i=0;i<n;i++)
		cout<<setw(10)<<arr[i].name<<setw(15)<<arr[i].no<<endl;

}
