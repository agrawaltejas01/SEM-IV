//============================================================================
// Name        : Graph.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "adj_list.h"
#include<stdlib.h>
using namespace std;

int main()
{
	adj_list A;

	do
	{
		int ch;
		cout<<"\tMENU\n";

		cout<<"\t\t1.Create\n\t\t2.Display\n\t\t3.Friends\n\t\t4.Comments"
				"\n\t\t5.Date of birth\n\t\t6.Exit\n\n";
		cout<<"Enter Choice : ";
		cin>>ch;
		cout<<endl;

		switch(ch)
		{
			case 1:
				{
					int n;

					cout<<"Enter number of users in your network : ";
					cin>>n;
					cout<<endl;

					A.root=A.create(n);
					break;
				}

			case 2:
			{
					A.display(A.root);
					break;
			}

			case 3:
			{
					A.bfs(A.root);
					A.unvisit();
					A.dfs(A.root,0);

					cout<<"User having maximum friends : "<<A.popular<<endl;
					cout<<"Number of "<<A.popular<<" has is : "<<A.max_friends<<endl;
					break;

			}

			case 4:
			{
					A.unvisit();
					A.dfs(A.root,0);

					cout<<"Maximum comments have been made by : "<<A.social<<endl;
					cout<<"Number of comments made by "<<A.social<<" is "<<A.max<<endl<<endl;

					cout<<"Minimum comments have been made by : "<<A.introvert<<endl;
					cout<<"Number of comments made by "<<A.introvert<<" is "<<A.min<<endl;

					break;
			}

			case 5:
			{
					int month;
					cout<<"Enter month you are intrested in  : ";
					cin>>month;
					cout<<endl;

					A.unvisit();
					A.dfs(A.root,month);
					cout<<"Number of people having date of birth in month "
					<<month<<" : "<<A.same_month<<endl;

					break;
			}

		case 6:		exit(0);

		}
	}
	while(1);

	return 0;
}
