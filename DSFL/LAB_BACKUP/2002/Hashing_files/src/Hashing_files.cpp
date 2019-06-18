//============================================================================
// Name        : Hashing_files.cpp
// Author      : sagar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "hash_file.h"
#include"student.h"
using namespace std;

int main() {

	student s[100];
	hash_file r;

	do{

	cout<<"\t\t\t1.Insert\n\t\t\t2.Display\n\t\t\t3.Search\n\t\t\t4.Main Menu\n\n";
							cout<<"Enter your choice : ";

							int ch;
							cin>>ch;

							switch(ch)
							{
								case 1 :
											r.updatesize();
											s[0].create(s,r.getsize());

											for(int i=0;i<r.getsize();i++)
												r.insert(s[i]);
											break;

								case 2 :   r.display();
											break;

								case 3 :	ll x;
											cout<<"Enter a phone number you want to search : ";
											cin>>x;
											int res;
											res=r.search(x);
											if(res==-1)
												cout<<"\nNot found\n";
											else
												cout<<"\nFound at "<<res<<" \n";
											break;

								case 4:	main();

							}
						}
						while(1);
}
