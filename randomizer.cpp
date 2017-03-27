#include "randomizer.h"
#include <cstdlib>
#include <ctime>

bool Randomizer::singleRandomization(Graph *graph)
{
    srand(time(NULL));

    std::vector<Connection>connectionList=graph->getConnectionList();
    if(connectionList.size()<2){
        return false;
    }

    Connection connection=connectionList[std::rand()%connectionList.size()];
    std::vector<int> firstUnconnected;
    std::vector<int> secondUnconnected;

    bool ** matrix=graph->getAdjacencyMatrix();

    for(int i=0;i<graph->getVerticesNumber();i++){
        if(i!=connection.firstID && matrix[i][connection.firstID]==0){
            firstUnconnected.push_back(i);
        }
        if(i!=connection.secondID && matrix[i][connection.secondID]==0){
            secondUnconnected.push_back(i);
        }
    }

    std::vector<Connection> candidates;
    for(int i=0;i<firstUnconnected.size();i++){
        for(int j=0;j<secondUnconnected.size();j++){
            if(matrix[firstUnconnected[i]][secondUnconnected[j]]==1){
                Connection pair={firstUnconnected[i],secondUnconnected[j]};
                candidates.push_back(pair);
            }
        }
    }

    if(candidates.size()==0){
        return false;
    }

    Connection choosedConnection=candidates[std::rand()%candidates.size()];
    graph->disconnectVertices(connection.firstID,connection.secondID);
    graph->disconnectVertices(choosedConnection.firstID,choosedConnection.secondID);
    graph->connectVertices(connection.firstID,choosedConnection.firstID);
    graph->connectVertices(connection.secondID,choosedConnection.secondID);

    return true;
}

bool Randomizer::Randomize(Graph *graph, int times){
    int counter=0;
    for(int i=0;i<times;i++){
        if(!Randomizer::singleRandomization(graph)){
            i--;
        }
        else{
            counter=0;
        }
        if(counter>10000){
            break;
        }
        counter++;
    }
    if(counter>10000){
        return false;
    }
    return true;
}
