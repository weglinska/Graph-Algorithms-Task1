#include "hamiltoniancycle.h"

bool HamiltonianCycle::isSafe(int vertex, bool** Matrix, std::vector<int>& path, int position)
{
	if(Matrix[ path[position-1] ][vertex] == 0)
		return false;
	
	for(int i=0; i<position; i++)
		if(path[i]==vertex)
			return false;
	
	return true;
}

bool HamiltonianCycle::checkHamiltonianCycle(bool** Matrix, std::vector<int>& path, int position)
{
	if(position == (int)path.size())
	{
		if(Matrix[ path[position-1] ][path[0]] == 1)
			return true;
		else
			return false;
	}

	for(unsigned i=0; i<path.size(); i++)
	{
		if(HamiltonianCycle::isSafe((int)i, Matrix, path, position))
		{
			path[position] = (int)i;
			
			
			if(HamiltonianCycle::checkHamiltonianCycle(Matrix, path, position+1) == true)
				return true;

			path[position] = -1;
		}
	}

	return false;
}

std::vector<int> HamiltonianCycle::hamiltonianCycle(Graph* graph){
	bool** Matrix = graph->getAdjacencyMatrix();

	std::vector<int> path(graph->getVerticesNumber());
	for(int i=0; i<graph->getVerticesNumber(); i++){
		path[i] = -1;
	}

	path[0] = 0;

	if(HamiltonianCycle::checkHamiltonianCycle(Matrix, path, 1)==false){
        path.resize(1);
        path[0] = 0;

        return path;
	}

	return path;
}
