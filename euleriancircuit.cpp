#include "euleriancircuit.h"
#include "randomizer.h"
#include <iostream>


EulerianCircuit::EulerianCircuit() {}

std::vector<int> EulerianCircuit::getEulerianCircuit(Graph* graph)
{
    int verticesNumber = graph->getVerticesNumber();
    std::vector<int>* eulerianCircuit = new std::vector<int>;
    if(EulerianCircuit::IsGraphEulerian(graph))
    {
        bool** copyMatrix = new bool*[verticesNumber];
        for(int i=0; i<verticesNumber; i++)
            copyMatrix[i] = new bool[verticesNumber];

        for(int i=0; i<verticesNumber; i++)
        {
           for(int j=0; j<verticesNumber; j++)
                copyMatrix[i][j] = graph->getAdjacencyMatrixValue(i, j);
        }

        EulerianCircuit::EulerianCircuitRecursive(copyMatrix, verticesNumber, 0, eulerianCircuit);

        for(int i=0; i<verticesNumber; i++)
            delete [] copyMatrix[i];
        delete [] copyMatrix;
    }

    std::vector<int> result = *eulerianCircuit;
    delete eulerianCircuit;

    return result;
}

void EulerianCircuit::EulerianCircuitRecursive(bool** adjacencyMatrix, const int verticesNumber, int vertexIndex, std::vector<int>* eulerianCircuit)
{

    for(int j=0; j<verticesNumber; j++)
    {
        if(adjacencyMatrix[vertexIndex][j] == true)
        {
            adjacencyMatrix[vertexIndex][j] = adjacencyMatrix[j][vertexIndex] = false;
            EulerianCircuit::EulerianCircuitRecursive(adjacencyMatrix, verticesNumber, j, eulerianCircuit);
        }
    }
    eulerianCircuit->push_back(vertexIndex);
}

bool EulerianCircuit::IsGraphEulerian(Graph *graph)
{
    if(Consistent::getMaxConsistent(graph->getAdjacencyMatrix(),graph->getVerticesNumber()).size()!=graph->getVerticesNumber()){
       return false;
    }
    int verticesNumber = graph->getVerticesNumber();
    for(int i=0; i<verticesNumber; i++)
    {
       int sum = 0;
       for(int j=0; j<verticesNumber; j++)
            if(graph->getAdjacencyMatrixValue(i, j) == true) sum ++;
       if(sum%2 != 0)
           return false; 
    }
    return true;
}

Graph* EulerianCircuit::RandomizeEulerianGraph(Graph* eulerianGraph, int times)
{
    if(EulerianCircuit::IsGraphEulerian(eulerianGraph))
    {
        Randomizer::Randomize(eulerianGraph, times);
        return eulerianGraph;
    }
    return 0;
}

Graph* EulerianCircuit::getEulerianGraph(int size)
{
    srand (time(NULL));
    Graph * newGraph=NULL;

    do{
        delete newGraph;
        std::vector<int>seq=std::vector<int>(size,2);
        for(int i=0;i<seq.size();i++){
            for(int j=0;j<5;j++){
                seq[i]=((std::rand()+1)%((size)/2))*2;
                if(Sequence::IsGraphical(seq)){
                    break;
                }
                seq[i]=2;
            }
        }
        newGraph=Sequence::SequenceMatrix(seq);
    }while(Consistent::getMaxConsistent(newGraph->getAdjacencyMatrix(),size).size()!=size);

    return newGraph;
}
