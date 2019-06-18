/*
 * graph.h
 *
 *  Created on: 12-Mar-2018
 *      Author: e2002
 */

#ifndef GRAPH_H_
#define GRAPH_H_

struct edge
{
	int u,v,w;
};

class graph
{
	int n,span_number,edge_number;
	int G[100][100];
	edge e[100];
	edge data[100];

public:
	graph(){n=0;span_number=0;edge_number=0;}
	void getdata();
	void print_adj_matrix();

	void sort();
	void print_spanning_tree();
	void kruskal();


};

#endif /* GRAPH_H_ */
