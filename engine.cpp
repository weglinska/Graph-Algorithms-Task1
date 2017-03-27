#include "engine.h"

Engine::Engine(QObject *parent) : QObject(parent)
{
    myGraph=NULL;

}

Graph * Engine::getGraph(){
    return myGraph;
}

void Engine::removeGraph(){
    if(myGraph){
        delete myGraph;
    }
}

void Engine::setGraph(Graph * graph){
    path.clear();
    removeGraph();
    myGraph=graph;
    emit updateGraph();
}

void Engine::changeGraphSize(int newSize){
    path.clear();
    removeGraph();
    myGraph=new Graph(newSize);
    emit updateGraph();
}
Engine * Engine::engine=NULL;

Engine::Engine(const Engine &en){}

Engine * Engine::getInstance(){
    if(engine==NULL){
        engine=new Engine();
    }
    return engine;
}

void Engine::updateGraph(QObject * sender){
    path.clear();
    emit changedGraph(sender);
}

void Engine::setPath(std::vector<int> path){
    this->path=path;
    emit changedGraph(this);
}

