//============================================================================
// Name        : Dijkstra.cpp
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
	int src;

	do
		{
			int ch;
			cout<<"\tMENU\n";

			cout<<"\t\t1.Create graph\n\t\t2.Display adjacency list\n\t\t3.Dijkstra\n\t\t4.Distance"
					"\n\t\t5.Exit\n\n";
			cout<<"Enter Choice : ";
			cin>>ch;
			cout<<endl;

			switch(ch)
			{
			case 1 :	g.getdata();
						cout<<endl<<endl;
						break;

			case 2 : 	g.display_adj_list();
						cout<<endl<<endl;
						break;

			case 3 :	cout<<"Enter source : ";
						cin>>src;
						cout<<endl<<endl;

						g.dijkstras(src);
						cout<<"Dijkstra successfully applied !!!\n\n ";
						cout<<endl<<endl;
						break;

			case 4 :	g.print_solution(src);
						cout<<endl<<endl;
						break;

			case 5 : 	exit(0);

			}
		}
	while(1);

	return 0;
}
