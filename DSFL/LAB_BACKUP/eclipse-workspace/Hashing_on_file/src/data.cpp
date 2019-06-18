/*
 * data.cpp
 *
 *  Created on: 26-Mar-2018
 *      Author: e2002
 */

#include "data.h"
#include<string>
#include<iostream>
#include<fstream>
#include<malloc.h>
#include<iomanip>
using namespace std;


void data:: init()
{
	cout<<"Enter Total number of records : ";
	cin>>rec;
	cout<<endl;

	for(int i=0;i<rec;i++)
	{
		arr[i].Name="...";
		arr[i].id=-1;
		arr[i].link=-1;
		arr[i].loc=-1;

		flag[i]=0;
		chain[i]=-1;
	}

	write();
}

void data:: display()
{
	for(int i=0;i<rec;i++)
	{
			cout<<setw(15)<<arr[i].Name<<setw(15)<<arr[i].id<<setw(5)<<chain[i]<<endl;
	}
}

void data:: write()
{
	fstream fp;

	fp.open("out.txt",ios::app);
	for(int i=0;i<rec;i++)
	{
		fp<<setw(15)<<arr[i].Name<<setw(15)<<arr[i].id<<setw(5)<<chain[i]<<endl;
	}

	fp.close();
}

int data:: hash(int x)
{
	return x%10;
}

void data:: insert()
{
	for(int idx=0;idx<rec;idx++)
	{
		record obj;

		cout<<"Enter Total number of records : ";
		cin>>obj.Name;
		cout<<endl;

		cout<<"Enter Total number of records : ";
		cin>>obj.id;
		cout<<endl;

		int i=0,start;
		start=hash(obj.id);



		while(flag[start])				//locate begining
		{
			if(hash(arr[start].id) == hash(obj.id))
				break;

			start=hash(start+1);
		}

		int j=start;

		while(chain[j] != -1)	//go to end of chain or empty location
			j=chain[j];

		start=j;

		while(flag[start])
		{
			start=hash(start+1);
			i++;
		}

		arr[start]=obj;
		flag[start]=1;

		if(j != start)
			chain[j]=start;
	}
	write();
}

