#ifndef HAMILTONIANCYCLE_H
#define HAMILTONIANCYCLE_H

#include "graph.h"

class HamiltonianCycle
{
	public:
		static std::vector<int> hamiltonianCycle(Graph* graph);
	private:
		static bool checkHamiltonianCycle(bool** Matrix, std::vector<int>& path, int position);
		static bool isSafe(int vertex, bool** Matrix, std::vector<int>& path, int position);
};

#endif