//============================================================================
// Name        : Binary_Search_Tree.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "BST.h"
#include<stdlib.h>
using namespace std;

int main()
{
	node * s;
	BST b;

	do
		{
			int ch;
			cout<<"\tMENU\n";

			cout<<"\t\t1.Create\n\t\t2.Delete\n\t\t3.Search\n\t\t4.Mirror Image"
					"\n\t\t5.Display\n\t\t6.Display Level Wise\n\t\t7.Height of Tree\n\t\t8.Exit\n\n";
			cout<<"Enter Choice : ";
			cin>>ch;
			cout<<endl;

			switch(ch)
			{
			case 1:
					{
						int n;
						cout<<"Enter number of values you want to enter in BST : ";
						cin>>n;

						for(int i=0;i<n;i++)
						{
							cout<<"Enter Element number "<<i+1<<" : ";
							int x;
							cin>>x;

							b.create(x);
						}
						cout<<"Binary Search tree created !!!!\n\n";
						break;
					}

			case 2:
					{
						int x;
						cout<<"Enter node you want to delete : ";
						cin>>x;

						b.root=b.Delete(b.root,x);
						cout<<"\n\n";
						break;
					}

			case 3:
					{
						int x;
						cout<<"Enter node you want to search : ";
						cin>>x;
						s=b.search(b.root,x);
						cout<<"\n\n";
						break;
					}

			case 4:
					{
						node *m;
						m=b.mirror(b.root);
						cout<<"Mirror Image created \n\n";

						cout<<"Created tree in Inorder is : ";
						b.display(m);
						cout<<"\n\n";
						break;
					}

			case 5:
					{
						cout<<"Created tree in Inorder is : ";
						b.display(b.root);
						cout<<"\n\n";
						break;
					}

			case 6:
					{
						cout<<"Created tree in Level order is : ";
						b.display_level(b.root);
						cout<<"\n\n";
						break;
					}

			case 7:
					{
						cout<<"Height of tree is : "<<b.height(b.root)<<endl<<endl;
						break;
					}

			case 8:
					{
						exit(0);
						break;
					}
			}
		}
		while(1);

	return 0;
}
