//============================================================================
// Name        : Linked_List.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "linked.h"
using namespace std;

int main()
{
	int n;

	cout<<"Length of linked list :";
	cin>>n;
	cout<<endl;

	linked l;

	node *p,*q;

	p=l.create(n);
	l.display(p);

	int val,pos;

	/*cout<"Enter Value you want to delete : ";
	cin>>val;
	cout<<endl;

	q=l.del(n,p,val);
	p=q;
	l.display(p);*/

	cout<<"Enter Value you want to Enter: ";
	cin>>val;
	cout<<endl;

	cout<<"Enter Position you want to Enter: ";
	cin>>pos;
	cout<<endl;

	q=l.insert(n,p,val,pos);
	p=q;
	l.display(p);


	return 0;

}
