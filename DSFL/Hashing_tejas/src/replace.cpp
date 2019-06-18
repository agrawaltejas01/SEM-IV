/*
 * replace.cpp
 *
 *  Created on: 18-Mar-2018
 *      Author: deception
 */

#include "replace.h"
#include "student.h"
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

replace::replace()
{
	for(int i=0;i<20;i++)
	{
		flag[i]=0;
		chain[i]=-1;
	}

	size=0;
}

int replace :: hash(long long int x)
{
	return (x%size);
	//return x%10;
}

void replace :: insert(student s[],int n)
{
	size=n;
	for(int std_idx=0;std_idx<size;std_idx++)
	{
		long long int ph_no=s[std_idx].no;

		int start=hash(ph_no);


		if(flag[start]==0)				//if desired location is empty
		{
			data[start]=s[std_idx];
			flag[start]=1;

			//cout<<start<<endl;

			continue;
		}

		//cout<<"IGI\n";

		if(hash(data[start].no) != hash(ph_no))	//no synonym
		{
			int i=0,j=start;			// i will be index of data	j=index of next empty location
			while(flag[j])		//locate next empty location
			{
				j = hash(j+1);
			}						//j=empty location

			i = hash(data[start].no);		//if 53 is to be inserted then on 3 if 55 is there then go to 55%10 (5)

			while(chain[i] != start)	//go to end of synonym of element who sent data at desired location of current start
									//go to the element that points to desired location ie the one from 5s' link that point to 3
				i=chain[i];

			chain[i]=chain[start];	//modify last element chain			//make that element point to next element of data

			//int extra=start;
			int extra=i;

			while(chain[extra] != -1)				// goto the end of chain from data
				extra=chain[extra];

			chain[extra]=j;			//make it point to empty element j
									// update chain of element who sent incorrect data at desired location of current start
			data[j]=data[start];		//insert data at empty element
			flag[j]=1;				//make flag 1

			data[start]=s[std_idx];		//make curr_element = start
			chain[start]=-1;
			continue;
		}

		int i=0,j=start;			// i will be index of data	j=index of next empty location
		while(flag[j] && i<size)	//locate next empty location
		{
			j = hash(j+1);
		}

		data[j]=s[std_idx];
		flag[j]=1;
		chain[j]=-1;

		i=start;
		while(chain[i] != -1)	// traverse upto start element
			i=chain[i];

		chain[i]=j;				// update chain of start
	}
}

void replace :: display()
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

void replace :: search(long long int x)
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
			cout<<"Elemnt found at index : ";
			cout<<j<<endl;
			return;
		}

		j=chain[j];
	}

	cout<<"No match found !!";
	return;
}
