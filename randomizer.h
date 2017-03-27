#ifndef RANDOMIZER_H
#define RANDOMIZER_H
#include <graph.h>


class Randomizer
{
public:
    static bool Randomize(Graph *graph, int times);
private:
    static bool singleRandomization(Graph * graph);
};

#endif // RANODMIZER_H
