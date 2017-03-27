#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <iostream>
#include <cstdlib>

struct Connection{
    int firstID;
    int secondID;
    int getMax()const {
        return ((firstID > secondID) ? firstID : secondID);
    }
};

class Graph{
    int _verticesNumber;
    bool** _adjacencyMatrix;
public:
    static Graph* pointSideGenerator(const int n, const int l);
    static Graph* copyFromAdjancencyList(std::vector<std::vector<int> > adjancencyList);
    static Graph* pointProbabilityGenerator(const int n, const double p);
    static Graph* copyFromConnectionList(std::vector<Connection> connectionList);
    static Graph* copyFromConnectionMatrix(std::vector<std::vector<bool> > connectionMatrix);

    Graph(int size);
    Graph(bool** Matrix, const int number);
    ~Graph();
    int getVerticesNumber();
    bool * operator [](int pos);
    void connectVertices(int firstID,int secondID);
    void disconnectVertices(int firstID,int secondID);
    bool getAdjacencyMatrixValue(int firstID,int secondID);
    std::vector<std::vector<int> > getAdjacencyList();
    void printAdjacencyList();
    void printAdjacencyMatrix();
    std::vector<Connection> getConnectionList();
    std::vector<std::vector<bool> > getConnectionMatrix();
    bool** getAdjacencyMatrix() const;
    int GetVerticesNumber() const;
};


#endif // GRAPH_H
