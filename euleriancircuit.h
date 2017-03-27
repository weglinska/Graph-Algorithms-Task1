#ifndef EULERIANCIRCUIT_H
#define EULERIANCIRCUIT_H
#include <vector>
#include "graph.h"
#include "consistent.h"
#include "sequence.h"
#include <stdlib.h>
#include <time.h>
class EulerianCircuit
{
private:
    EulerianCircuit();
public:
    static std::vector<int> getEulerianCircuit(Graph* graph);
    static void EulerianCircuitRecursive(bool** adjacencyMatrix, const int verticesNumber, int vertexIndex, std::vector<int>* eulerianCircuit);
    static bool IsGraphEulerian(Graph* graph);
    static Graph* RandomizeEulerianGraph(Graph* eulerianGraph, int times);
    static Graph* getEulerianGraph(int size);
};

#endif // EULERIANCIRCUIT_H
