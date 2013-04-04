//
//  graph.h
//  ucarpp
//
//  Created by Maurizio Zucchelli on 03/25/13.
//  Copyright (c) 2013 Marco Maddiona, Riccardo Orizio, Mattia Rizzini, Maurizio Zucchelli. All rights reserved.
//

#ifndef __ucarpp__graph__
#define __ucarpp__graph__

#include <stdlib.h>
#include <vector>
#include <queue>

#include "edge.h"

using namespace std;
typedef unsigned int uint;

class Graph
{
	// Numero di Vertici
	int V;
	// Matrice dei Costi
	int** costs;
	// Lista di Adiacenza
	vector<Edge>* edges;
	
public:
	Graph( int );
	void addEdge( uint, uint, uint, uint, float );
	void completeCosts();
};

#endif /* defined(__ucarpp__graph__) */
