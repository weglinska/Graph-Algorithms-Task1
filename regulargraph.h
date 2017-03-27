#ifndef REGULARGRAPH_H
#define REGULARGRAPH_H
#include "sequence.h"


class RegularGraph
{
private:
    RegularGraph();
public:
    static Graph* getRandomRegularGraph(const int degree, const int number);
};

#endif // REGULARGRAPH_H
