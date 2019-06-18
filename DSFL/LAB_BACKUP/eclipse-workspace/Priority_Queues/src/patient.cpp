/*
 * patient.cpp
 *
 *  Created on: 31-Jan-2018
 *      Author: e2002
 */

#include "queues.h"
#include<iostream>
#include<malloc.h>
#include<string>
#include<iomanip>
#include"patient.h"
using namespace std;

int  priority(int s)
{
	if(s==1 || s==2)
		return 1;

	else if(s==3 || s==4)
		return 2;

	else
		return 3;
}

node * patient:: getdata()
//node * queues:: getdata()
{
	node *n;
		n=new node;
		int ch;

		cout<<"Enter Name of Patient : ";
		cin>>n->name;
		cout<<endl;

		cout<<"Enter Address of Patient : ";
		cin>>n->add;
		cout<<endl;

		cout<<"Enter Phone Number of Patient : ";
		cin>>n->ph_no;
		cout<<endl;

		cout<<"Enter Disease of Patient : ";
		cout<<"\n\n\t1.Cancer\n\t2.Accident\n\t3.Blood Pressure\n\t4.Sugar\n\t5.Fever\n\t"
				"6.Cold\n\t";

		cout<<"Enter Option from Above Serviced Disease : ";
		cin>>ch;
		cout<<endl;

		switch (ch)
		{
			case 1 : n->dis="Cancer";
					 break;

			case 2 : n->dis="Accident";
					 break;

			case 3 : n->dis="BP";
					 break;

			case 4 : n->dis="Sugar";
					 break;

			case 5 : n->dis="Fever";
					 break;

			case 6 : n->dis="Cold";
					 break;

			default : cout<<"Choose From Disease Above\n";
					  break;

		}

		n->pri=priority(ch);

		cout<<endl;

		n->link=NULL;

		return n;
}
