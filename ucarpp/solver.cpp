//
//  solver.cpp
//  ucarpp
//
//  Created by Maurizio Zucchelli on 2013-04-13.
//  Copyright (c) 2013 Marco Maddiona, Riccardo Orizio, Mattia Rizzini, Maurizio Zucchelli. All rights reserved.
//

#include "solver.h"

/*** Solver ***/

Solver::Solver( Graph graph, uint depot, uint M ):
	graph( graph ), M( M ), depot( depot )
{
	currentSolution = (Solution*)calloc( M, sizeof( Solution ) );
	for ( int i = 0; i < M; i++ )
		currentSolution[ i ] = *new Solution();
}

Solution Solver::createBaseSolution()
{
	uint currentNode = depot;
	
	// Ordino i lati uscenti dal nodo corrente
	vector<Edge*> edges = graph.getAdjList( currentNode );
	sort( edges.begin(), edges.end(), greedyCompare );
	
	//for ( Edge* edge : edges )
	for ( int i = 0; i < edges.size(); i++ )
		cout << edges[ i ]->getSrc() + 1 << " " << edges[ i ]->getDst() + 1 << ": "
			 << edges[ i ]->getProfitDemandRatio() << endl;
	
	return *new Solution();
}

Solution Solver::solve()
{
	return createBaseSolution();
}


/*** Solution ***/
Solution::Solution()
{
	path = *new vector<Edge*>();
}

void Solution::addEdge( Edge* edge )
{
	path.push_back( edge );
}