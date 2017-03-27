#include "regulargraph.h"
#include "randomizer.h"

RegularGraph::RegularGraph() {}

Graph* RegularGraph::getRandomRegularGraph(const int degree, const int number)
{
    int* array = new int[number];
    for(int i=0; i<number; i++)
        array[i] = degree;

    if(Sequence::IsGraphical(array, number))
    {
        Graph* regularGraph = Sequence::SequenceMatrix(array, number);
        delete [] array;
        Randomizer::Randomize(regularGraph, 10);
        return regularGraph;
    }
    else
    {
        std::cout << "Sekwencja nie jest ciagiem graficznym" << std::endl;
    }
    return 0;
}
