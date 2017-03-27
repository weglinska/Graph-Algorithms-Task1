#include "sequence.h"
#include <algorithm>

Sequence::Sequence()
{

}

void Sequence::Sort(int *tab, int size)
{
    for (int i=0; i<size; ++i)
    {
        for (int j=0; j<size-1; ++j)
        {
            if (tab[j]<tab[j+1])
            std::swap (tab[j], tab [j+1]);
        }
    }
}

void Sequence::SortPair(std::pair<int,int> *tab, int size)
{
    for (int i=0; i<size; ++i)
    {
        for (int j=0; j<size-1; ++j)
        {
            if (tab[j].first<tab[j+1].first)
            std::swap (tab[j], tab [j+1]);
        }
    }
}


bool Sequence::IsGraphical(std::vector<int> tab)
{
    int size=tab.size();
    bool graphical=true;

    int array[size];

    for (int i=0; i<size; ++i)
    {
        array[i]=tab[i];
    }

    Sort(array,size);

    for (int i=0; i<size; ++i)
    {
        int id=1;
        while (array[0]!=0 && id<size)
        {
            array[0]--;
            if(array[id]==0){
                graphical=false;
            }
            array[id]--;
            id++;
        }
        if(id==size && array[0]!=0){
            graphical=false;
            break;
        }
        Sort(array,size);
    }
    return graphical;
}

Graph* Sequence::SequenceMatrix(std::vector<int> tab)
{
    int size=tab.size();

    bool** Matrix = new bool*[size];
    for(int i=0; i<size; ++i)
    {
       Matrix[i] = new bool[size];

       for(int j=0; j<size; j++)

              Matrix[i][j] = 0;
    }

    typedef std::pair<int, int> pair;
    pair array[size];

    for (int i=0; i<size; ++i)
    {
        array[i].first=tab[i];
        array[i].second=i;
    }


    SortPair(array,size);

    for (int i=0; i<size; ++i)
    {
        int id=1;
        while (array[0].first!=0 && id<size)
        {
            Matrix[array[0].second][array[id].second]=1;
            Matrix[array[id].second][array[0].second]=1;

            array[0].first--;
            array[id].first--;

            id++;
        }
        SortPair(array,size);
    }

    return new Graph(Matrix, size);
}
