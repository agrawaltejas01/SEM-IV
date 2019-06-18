/*
 * file.cpp
 *
 *  Created on: 11-Apr-2018
 *      Author: hp
 */

#include "file.h"
#include<iostream>
using namespace std;
file::file() {
	// TODO Auto-generated constructor stub

}
student getdata() {
	student s;
	cout << "enter name";
	cin >> s.name;
	cout << "enter roll no";
	cin >> s.rollno;
	return s;
}
void file::add() {
	student t;
	of.open("temp.txt", ios::app | ios::binary | ios::out);
	t = getdata();
	of.write((char*) &t, sizeof(t));
	of.close();
}
void file::create(int n) {

	student t;
	of.open("temp.txt", ios::out | ios::binary);
	for (int i = 0; i < n; i++) {
		t = getdata();
		of.write((char*) &t, sizeof(t));
	}
	of.close();
}
void file::display() {
	student t;
	of.open("temp.txt", ios::in | ios::binary);
	of.seekg(0, ios::beg);
	of.read((char*) &t, sizeof(t));
	while (of) {
		cout << t.name << "  " << t.rollno << endl;
		of.read((char*) &t, sizeof(t));
	}
	of.close();

}

int file::search(int p) {
	student t;
	of.open("temp.txt", ios::in | ios::binary);
	of.seekg(0, ios::beg);
	of.read((char*) &t, sizeof(t));
	while (of) {
		if (t.rollno == p) {
			cout << "record found   ";
			cout << t.name << "   " << t.rollno;
			return 1;
		}

		of.read((char*) &t, sizeof(t));
	}


		of.close();
		return 0;
	}
	void file::delete_record(int p) {
		student t;
		fstream of1;
		of.open("temp.txt",ios::in | ios::binary);
		of1.open("temp1.txt",ios::out | ios::binary);
		of.seekg(0,ios::beg);
		of.read((char*)&t,sizeof(t));
		while(of) {
			if(t.rollno!=p) {
				of1.write((char*)&t,sizeof(t));
			}
			of.read((char*)&t,sizeof(t));
		}
		//cout<<"record not found"<<endl;
		of1.close();
		of.close();
		remove("temp.txt");
		rename("temp1.txt","temp.txt");

	}

	file::~file()
	{
		// TODO Auto-generated destructor stub
	}

