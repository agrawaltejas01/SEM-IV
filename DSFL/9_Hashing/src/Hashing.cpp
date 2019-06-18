//============================================================================
// Name        : Hashing.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "student.h"
#include "replace.h"
#include "no_replace.h"
#include<stdlib.h>
using namespace std;

int main()
{
	student s[10];
	do
	{
		cout<<"------MENU-------\n\n";
		cout<<"\t1.With Replacement\n\t2.Without Replacement\n\t3.exit\n\n";
		cout<<"Enter your choice : ";
		int opt;
		cin>>opt;
		cout<<endl;

		switch(opt)
		{
				case 1:
				{
					replace r;
					do
					{
						cout<<"\t\t-----With Replacement------\n";
						cout<<"\t\t\t1.Insert\n\t\t\t2.Display\n\t\t\t3.Search\n\t\t\t4.Main Menu\n\n";
						cout<<"Enter your choice : ";

						int ch;
						cin>>ch;

						switch(ch)
						{
							case 1 :    s[0].create(s);
										r.insert(s,s[0].n);
										cout<<"IGI\n";
										break;

							case 2 :    r.display();
										break;

							case 3 :	long long int x;
										cout<<"Enter a phone number you want to search : ";
										cin>>x;
										r.search(x);
										cout<<endl;
										break;

							case 4 :    main();

						}
					}
					while(1);
				}
				break;

				case 2:
				{
					no_replace r;
					do
					{
						cout<<"\t\t-----Without Replacement------\n";
						cout<<"\t\t\t1.Insert\n\t\t\t2.Display\n\t\t\t3.Search\n\t\t\t4.Main Menu\n\n";
						cout<<"Enter your choice : ";

						int ch;
						cin>>ch;

						switch(ch)
						{
							case 1 :    s[0].create(s);
										r.insert(s,s[0].n);
										cout<<"IGI\n";
										break;

							case 2 :    r.display();
										break;

							case 3 :	long long int x;
										cout<<"Enter a phone number you want to search : ";
										cin>>x;
										r.search(x);
										cout<<endl;
										break;

							case 4 :    main();

						}
					}
					while(1);
				}
				break;

				case 3 : exit(0);
		}
	}
	while(1);

	return 0;
}
