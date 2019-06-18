/*
 * hash_file.cpp
 *
 *  Created on: 26-Mar-2018
 *      Author: e2007
 */

#include "hash_file.h"
#include<fstream>
#include<iomanip>
hash_file::hash_file() {

	for(int i=0;i<50;i++)
	{
		flag[i]=0;
		chain[i]=-1;
	}

	size=0;
	student s;
	s.num=0;
	s.name="";
	fstream outfile;
		outfile.open("data.txt",ios::out | ios :: binary);
		outfile.seekp(0,ios::beg);
		for(int i=0;i<10;i++)
			outfile.write((char *) &s, sizeof(s));
			//outfile<<s.name<<"\t\t"<<s.num;

}

int hash_file:: hash(ll x)
{
	//return (x%size);
	return x%10;
}

void hash_file::insert(student s)
{
	fstream outfile;
	outfile.open("data.txt",ios::in| ios::app| ios :: binary);
	int i=0,j,start;

	start=hash(s.getnum());
	outfile.seekg(sizeof(student)*start,ios::beg);

	student read_from_file;
	outfile.read( (char *) &read_from_file, sizeof(read_from_file)) ;
	//outfile>>read_from_file.name>>read_from_file.num;

	while(flag[start]==1&&i<size)			//go to begining
	{
		if(hash(s.getnum())==hash(read_from_file.getnum()))
			break;

		i++;
		start=hash(start+1);
		//outfile.seekg(sizeof(student)*start,ios::beg);
		outfile.read( (char *) &read_from_file, sizeof(read_from_file)) ;
		//outfile>>read_from_file.name>>read_from_file.num;
	}

	if(i==size)
	{
		cout<<"\nHASH TABLE FULL";
		return;
	}
	//j=start;//outfile<<s.name<<"\t\t"<<s.num;

	//end of chain

	while(chain[start]!=-1)
	{
		start=chain[start];
	}

	//chain -1 element

	j=start;

	while(flag[j]&&i<size)
	{
		j=hash(j+1);
		i++;
	}

	if(i==size)
		{
			cout<<"\nHASH TABLE FULL";
			return;
		}

	//store

	outfile.close();

		outfile.open("data.txt", ios::out | ios::app| ios :: binary);
	outfile.seekp(sizeof(student)*j,ios::beg);
	outfile.write((char *) &s, sizeof(s));

	//outfile<<read_from_file.name<<"\t\t"<<read_from_file.num;
	data[j]=s;
	flag[j]=1;

	if(j!=start)
		chain[start]=j;		//update chain
	outfile.close();
}


void hash_file :: display()
{
	fstream outfile;
		outfile.open("data.txt",ios::out);
	outfile.seekg(0,ios::beg);
	student Stu;
	while( (outfile.read((char*)&Stu,sizeof(Stu))) != NULL )
		cout<<Stu.name<<" ";
	cout<<setw(10)<<"Name"<<setw(15)<<"Phone no."<<setw(15)<<"Chain"<<"\n";
	cout<<"---------------------------------------------------------------------";
	cout<<"\n";

	for(int i=0;i<10;i++)
	//for(int i=0;i<size;i++)
	{
			if(flag[i])
			{
				outfile.seekg(i*sizeof(student),ios::beg);
				student s;
				outfile.read((char *) &s, sizeof(s));
				//cout<<"\t"<<data[i].name;
				cout<<setw(10)<<s.name<<setw(15)<<s.getnum()<<setw(15)<<chain[i]<<"\n";
			}

			else
				cout<<setw(10)<<"----"<<setw(15)<<"----"<<setw(15)<<chain[i]<<"\n";
	}
	outfile.close();
}

int hash_file::search(ll no)
{
	int i=0,j;

	j=hash(no);
	//locate beg of chain
	while(i<size && flag[j] && hash(data[j].getnum())==hash(no))
	{
		i++;
		j=hash(j+1);
	}

	if(!flag[j]||i>=size)
		return -1;

	//locate element
	while(j!=-1)
	{
		if(data[j].getnum()==no)
			return j;

		j=chain[j];
	}

	return -1;

}


void hash_file::updatesize()
{
	cout<<"Enter number of students : ";
		cin>>size;
		cout<<"\n";

}

int hash_file::getsize()
{
	return size;
}
