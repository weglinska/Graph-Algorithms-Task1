#ifndef SEQUENCE_H
#define SEQUENCE_H
#include "graph.h"

class Sequence
{
public:
    Sequence();
    static bool IsGraphical(std::vector<int> tab);
    static Graph* SequenceMatrix(std::vector<int> tab);
private:
    static void Sort(int *tab, int size);
    static void SortPair(std::pair<int,int> *tab, int size);

};

#endif // SEQUENCE_H
