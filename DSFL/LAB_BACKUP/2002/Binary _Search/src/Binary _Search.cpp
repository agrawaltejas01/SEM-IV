//============================================================================
// Name        : Binary.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "sort.h"
#include "binary_search.h"
using namespace std;

int main()
{
	int n;

	cout<<"Length : ";
	cin>>n;
	cout<<endl;

	int arr[n];

	for(int i=0;i<n;i++)
	{
		cout<<"Element : ";
		cin>>arr[i];
		cout<<endl;
	}

	sort o;
	binary_search s;

	o.bsort(arr,n);

	cout<<"Given Array is : ";

	for(int i=0;i<n;i++)
		cout<<""<<arr[i]<<" ";

	cout<<endl;

	int val;

	cout<<"Key : ";
	cin>>val;
	cout<<endl;

	int result;
	result=s.bsearch(arr,0,n-1,val);

	cout<<""<<result<<endl;

	return 0;
}
