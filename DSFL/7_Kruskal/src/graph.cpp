/*
 * graph.cpp
 *
 *  Created on: 12-Mar-2018
 *      Author: e2002
 */

#include "graph.h"
#include<iostream>
#include<string>
using namespace std;

void graph:: getdata()
{
	cout<<"Enter number of nodes : ";
	cin>>n;
	cout<<endl<<endl;
      cout<<"Enter Adjecency matrix ::\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>G[i][j];
		}
	}


}

void graph:: print_adj_matrix()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<G[i][j]<<" ";

		cout<<endl;
	}
}

void graph:: sort()
{
	for(int i=0;i<edge_number-1;i++)
	{
		for(int j=0;j<edge_number-i-1;j++)
		{
			if(e[j].w > e[j+1].w)
			{
				edge temp=e[j];
				e[j] = e[j+1];
				e[j+1]=temp;
			}
		}
	}
}

void graph:: print_spanning_tree()
{
	int cost=0;

	for(int i=0;i<span_number;i++)
	{
		cout<<data[i].u<<" "<<data[i].v<<" "<<data[i].w<<endl;
		cost+=data[i].w;
	}

	cout<<"Cost of Spanning tree is : "<<cost<<endl;
}

int find(int arr[],int n)
{
	return arr[n];
}

void uni(int arr[],int v1,int v2,int n)
{
	for(int i=0;i<n;i++)
	{
		if(arr[i]==v2)
			arr[i]=v1;
	}
}

void graph:: kruskal()
{
	int check[100];
	edge span;

	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(G[i][j] != 0)
			{
				e[edge_number].u=i;
				e[edge_number].v=j;
				e[edge_number].w=G[i][j];

				edge_number++;
			}
		}
	}							// edges inserted

	sort();						//sorted

	for(int i=0;i<edge_number;i++)	//check initialized
		check[i]=i;


	int v1,v2;
	for(int i=0;i<edge_number;i++)
	{
		v1=find(check,e[i].u);		//check cycle
		v2=find(check,e[i].v);

		if(v1 != v2)
		{
			data[span_number]=e[i];
			span_number++;

			uni(check,v1,v2,n);
		}
	}


}
