**Repozytorium projektów 1 i 2 dotyczących grafów.**

TIP1:
Nie dodajemy już metod do klasy graph. Do wszelkiego rodzaju obiektów stosujemy fabryki (klasy z funkcjami statycznymi zwracającymi wskaźnik na nowy obiekt):

```
#!c++

#ifndef SEQUENCE_H
#define SEQUENCE_H
#include "graph.h"

class Sequence
{
public:
    Sequence();
    static bool IsGraphical(int *tab, int size);
    static Graph* SequenceMatrix(int *tab, int size);

private:
    static void Sort(int *tab, int size);
    static void SortPair(std::pair<int,int> *tab, int size);
};

#endif // SEQUENCE_H
```

TIP2: 
QT i pliki o nazwach *.pro.user nie powinny być wysyłane do repozytorium (są to lokalne ustawienia).

TIP3:
Staramy się pisać kod możliwie "czysty" ([prezentacja](http://math.uni.lodz.pl/~mmisiak/zpi/studenci/czystykod.pdf)) ale bez przesady ;) .

TIP4:
Jako, że w końcu ruszyliśmy z gitem przed każdym posiedzeniem wykonujemy pull aby być na bieżąco ze zmianami w projekcie.  