/*
 * no_replace.cpp
 *
 *  Created on: 18-Mar-2018
 *      Author: deception
 */

#include "no_replace.h"
#include "student.h"
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

no_replace::no_replace()
{
	for(int i=0;i<20;i++)
		{
			flag[i]=0;
			chain[i]=-1;
		}

		size=0;
}

int no_replace :: hash(long long int x)
{
	//return (x%size);
	return x%10;
}

void no_replace:: insert(student s[],int n)
{
	size=n;
	for(int stud_idx=0;stud_idx<size;stud_idx++)
	{
		int i=0,start;
		start=hash(s[stud_idx].no);

		while(flag[start])				//locate begining
		{
			if(hash(data[start].no) == hash(s[stud_idx].no))
				break;

			i++;
			start=hash(start+1);
		}

		int j=start;

		while(chain[j] != -1)	//go to end of chain or empty location
			j=chain[j];

		int curr_loc=j;

		while(flag[curr_loc])
		{
			curr_loc=hash(curr_loc+1);
			i++;
		}

		data[curr_loc]=s[stud_idx];
		flag[curr_loc]=1;

		if(j != curr_loc)
			chain[j]=curr_loc;


	}
}

void no_replace :: display()
{
	cout<<setw(10)<<"Name"<<setw(15)<<"Phone no."<<setw(15)<<"Chain"<<endl;
	cout<<"---------------------------------------------------------------------";
	cout<<endl;

	for(int i=0;i<10;i++)
	//for(int i=0;i<size;i++)
	{
			if(flag[i])
				cout<<setw(10)<<data[i].name<<setw(15)<<data[i].no<<setw(15)<<chain[i]<<endl;

			else
				cout<<setw(10)<<"----"<<setw(15)<<"----"<<setw(15)<<chain[i]<<endl;
	}
}


void no_replace :: search(long long int x)
{
	int i=0,j;
	j=hash(x);

	while(i<size && flag[j] && hash(data[j].no)!=hash(x))
	{
		i++;
		j=hash(j+1);
	}

	if( !flag[j] || i==size)
	{
		cout<<"No match found !!";
		return;
	}

	while(j!=-1)
	{
		if(data[j].no == x)
		{
			cout<<"Element found at index : ";
			cout<<j<<endl;
			return;
		}

		j=chain[j];
	}

	cout<<"No match found !!";
	return;
}
