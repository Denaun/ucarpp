//
//  solver.h
//  ucarpp
//
//  Created by Maurizio Zucchelli on 2013-04-13.
//  Copyright (c) 2013 Marco Maddiona, Riccardo Orizio, Mattia Rizzini, Maurizio Zucchelli. All rights reserved.
//

#ifndef __ucarpp__solver__
#define __ucarpp__solver__

#define DEBUG

#include <unordered_set>
#include <sstream>

#include "headings.h"
#include "edge.h"
#include "graph.h"

class Solution
{
public:
	std::unordered_set<Edge*> path;
	
	Solution();
	
	void addEdge( Edge* );
	void removeEdge( Edge* );
	
	uint getCost( Graph );
	uint getDemand();

	string toString();
};

class Solver
{
private:
	Graph graph;
	uint depot,
		 M,
		 Q,
		 tMax;
	Solution* currentSolution;
	
	Solution createBaseSolution();
	
	
	struct compareRatioDescending
	{
		const Graph* graph;
		bool operator()( const Edge* lhs, const Edge* rhs ) const
		{
			// Ratio se lato non preso, -1 altrimenti
			float lhsRatio = ( lhs->getProfitDemandRatio() + 1 ) * ( lhs->getTaken() == 0 ) - 1,
				  rhsRatio = ( rhs->getProfitDemandRatio() + 1 ) * ( rhs->getTaken() == 0 ) - 1;
			if ( lhsRatio == rhsRatio )
				return graph->getCost( lhs ) > graph->getCost( rhs );
			
			return lhsRatio > rhsRatio;
		}
	};
	compareRatioDescending greedyCompare;
public:
	Solver( Graph, uint, uint, uint, uint );
	
	Solution solve();
	
	bool isFeasible( Solution );
};

#endif /* defined(__ucarpp__solver__) */
