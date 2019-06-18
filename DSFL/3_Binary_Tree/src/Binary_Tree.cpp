
                        //BINARY_TREE.cpp


/*
 Name        : Binary_Tree.cpp
 Author      : Tejas Agrawal
 Roll Number : 2002        
*/

#include <iostream>
#include<stdlib.h>
#include "b_tree.h"
using namespace std;

int main()
{
	b_tree b;
	node *r;

	node *p;
	node *copy;
	do
		{
			int ch;
			cout<<"\t----------------MENU------------------\n";

			cout<<"\t\t1.Create\n\t\t2.Depth of Tree\n\t\t3.Display Leaves\n\t\t4.Display tree\n\t\t"
					"5.Create a copy\n\t\t6.Level Display\n\t\t7.Exit\n\n";
			cout<<"Enter Choice : ";
			cin>>ch;
			cout<<endl;

			switch(ch)
			{
				case 1: r=b.create();
					    break;

				case 2:	cout<<"Height of tree is : "<<b.height(r)<<endl;
						break;

				case 3: cout<<"Leaf Nodes Are : ";
						p=b.display_leaf(r);
						cout<<"\n\n";
						break;

				case 4: cout<<"Tree in preorder is :: \n";
						b.display(r);
						cout<<"\n\n";
						break;

				case 5: copy=b.copy_tree(r);
						cout<<"\t\t!! Copied !!\n\n";
						b.display(copy);
						break;

				case 6:	cout<<"Tree in level order is :: \n";
						b.display_level(r);
						cout<<"\n\n";
						break;

				case 7:	exit(0);
						break;

			}
		}
		while(1);

	return 0;
}
