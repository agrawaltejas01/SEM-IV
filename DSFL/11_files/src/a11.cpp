//============================================================================
// Name        : a11.cpp
// Author      : avni
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include"file.h"
#include <iostream>
using namespace std;

int main() {
    file f;
    int x,x1,n,w;
    cout<<"enter no. of records to enter ";
        cin>>n;

    f.create(n);
    f.display();
    cout<<endl<<"enter roll no to search";
    cin>>x;
    w=f.search(x);
    if(w!=1){
    	cout<<"record not found"<<endl;
    }

    cout<<endl<<"enter roll no to delete";
       cin>>x1;
       f.delete_record(x1);
       f.display();

       cout<<"adding a record ";
       f.add();
       f.display();
	return 0;
}
