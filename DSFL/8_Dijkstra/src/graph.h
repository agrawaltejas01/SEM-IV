/*
 * graph.h
 *
 *  Created on: 12-Mar-2018
 *      Author: deception
 */

#ifndef GRAPH_H_
#define GRAPH_H_

class graph
{
	int n,dist[20];
	int G[100][100];
	int path[20];
	int path_idx;

	bool finalized[20];

public:
	void getdata();
	void display_adj_list();

	void unvisit();
	int pick_min();
	void dijkstras(int);
	void print_solution(int);
};

#endif /* GRAPH_H_ */
