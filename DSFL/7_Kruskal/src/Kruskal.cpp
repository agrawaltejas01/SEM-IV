//============================================================================
// Name        : Kruskal.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<stdlib.h>
#include "graph.h"
using namespace std;

int main()
{
	graph g;

	do
		{
			int ch;
			cout<<"\tMENU\n";

			cout<<"\t\t1.Enter Adjecency matrix\n\t\t2.Display Adjecency matrix\n\t\t3.Kruskal\n\t\t"
					"4.Display minimum spanning tree\n\t\t5.Exit\n\n";
			cout<<"Enter Choice : ";
			cin>>ch;
			cout<<endl;

			switch(ch)
			{
			case 1:		g.getdata();
						break;

			case 2:		g.print_adj_matrix();
						break;

			case 3:		g.kruskal();
			                  cout<<"Kruskal Succesfully applied!!\n\n";
						break;

			case 4:	    g.print_spanning_tree();
						break;

			case 5:		exit(0);
						break;

			}
		}
		while(1);

	return 0;

}
