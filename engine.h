#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>
#include <QTimer>
#include <vector>
#include "graph.h"
class Engine : public QObject
{
    Q_OBJECT

private:
    explicit Engine(QObject *parent = 0);
    Engine(const Engine & en);


public:
    static Engine * engine;
    static Engine * getInstance();
    Graph * myGraph;
    std::vector<int> path;
    Graph * getGraph();

    void removeGraph();
signals:
    void changedGraph(QObject * sender);
public slots:
    void setPath(std::vector<int> path);
    void updateGraph(QObject * sender = NULL);
    void changeGraphSize(int newSize);
    void setGraph(Graph *);
};

#endif // ENGINE_H
