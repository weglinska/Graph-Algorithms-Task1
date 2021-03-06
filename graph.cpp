#include "graph.h"
#include <ctime>

Graph::Graph(bool** Matrix, const int number) : _verticesNumber(number), _adjacencyMatrix(Matrix) {}
Graph::Graph(int verticesNumber):_verticesNumber(verticesNumber)
{
    _adjacencyMatrix=new bool* [_verticesNumber];
    for(int i=0;i<_verticesNumber;i++){
        _adjacencyMatrix[i]=new bool[_verticesNumber];
        for(int j=0;j<_verticesNumber;j++){
            _adjacencyMatrix[i][j]=false;
        }
    }
}

Graph::~Graph(){
    for(int i=0; i<this->_verticesNumber; i++){
        delete [] this->_adjacencyMatrix[i];
    }
    delete [] this->_adjacencyMatrix;
}

int Graph::getVerticesNumber(){
    return _verticesNumber;
}

bool* Graph::operator [](int pos){
    return _adjacencyMatrix[pos];
}

bool** Graph::getAdjacencyMatrix() const
{
    return this->_adjacencyMatrix;
}

void Graph::connectVertices(int firstID, int secondID){
    if(firstID!=secondID){
        _adjacencyMatrix[firstID][secondID]=true;
        _adjacencyMatrix[secondID][firstID]=true;
    }
}

void Graph::disconnectVertices(int firstID, int secondID){
    _adjacencyMatrix[firstID][secondID]=false;
    _adjacencyMatrix[secondID][firstID]=false;
}

bool Graph::getAdjacencyMatrixValue(int firstID, int secondID){
    return _adjacencyMatrix[firstID][secondID];
}

std::vector<std::vector<int> > Graph::getAdjacencyList(){
    std::vector<std::vector<int> > adjancencyList;
    for(int i=0; i<_verticesNumber; i++)
    {
            adjancencyList.push_back(std::vector<int>());
            for(int j=0; j<this->_verticesNumber; j++){
                if(this->_adjacencyMatrix[i][j] == true){
                    adjancencyList[i].push_back(j);
                }
            }
    }
    return adjancencyList;
}

std::vector<Connection> Graph::getConnectionList(){
    std::vector<Connection> connections;
    for(int i=0;i<_verticesNumber;i++){
        for(int j=i;j<_verticesNumber;j++){
            if(getAdjacencyMatrixValue(i,j)){
                Connection conn={i,j};
                connections.push_back(conn);
            }
        }
    }
    return connections;
}

std::vector<std::vector<bool> > Graph::getConnectionMatrix(){
    std::vector<Connection> connectionMap=getConnectionList();
    std::vector<std::vector<bool> > matrix=std::vector<std::vector<bool> >(connectionMap.size(),std::vector<bool>(_verticesNumber,false));

    for(unsigned i=0;i<connectionMap.size();i++){
        matrix[i][connectionMap[i].firstID]=true;
        matrix[i][connectionMap[i].secondID]=true;
    }
    return matrix;
}

void Graph::printAdjacencyList()
{
    for(int i=0; i<this->_verticesNumber; i++)
    {
        std::cout << i+1 << ": ";
        for(int j=0; j<this->_verticesNumber; j++)
            if(this->_adjacencyMatrix[i][j] == true)
                std::cout << j+1 << " ";
        std::cout << std::endl;
    }
}

void Graph::printAdjacencyMatrix()
{
    std::cout << "   ";
    for(int i=0; i<this->_verticesNumber; i++)
        std::cout << i+1 << " ";
    std::cout << std::endl;

    std::cout << "   ";
    for(int i=0; i<this->_verticesNumber; i++)
        std::cout << "__";
    std::cout << std::endl;

    for(int i=0; i<this->_verticesNumber; i++)
    {
        std::cout << i+1 << " |";
        for(int j=0; j<this->_verticesNumber; j++)
            std::cout << (this->_adjacencyMatrix[i][j] == true ? 1 : 0) << " ";
        std::cout << std::endl;
    }
}

Graph* Graph::pointSideGenerator(const int n, const int l)
{
    int max_l=0;
    for (int i=1; i<n; ++i) max_l+=i;

    bool** Matrix = new bool*[n];
    for(int i=0; i<n; ++i)
    {
       Matrix[i] = new bool[n];

       for(int j=0; j<n; j++)

              Matrix[i][j] = 0;
    }

    if (l<=max_l)
    {

        int counter=0;
        srand(time(NULL));
        int i, j;

        while(counter<l)
        {
            i=std::rand() % n;
            j=std::rand() % n;

            if((i!=j)&&(Matrix[i][j]==0))
            {
                Matrix[i][j]=Matrix[j][i]=1;
                ++counter;
            }
        }
    }

    return new Graph(Matrix, n);
}

Graph* Graph::pointProbabilityGenerator(const int n, const double p)
{

    bool** Matrix = new bool*[n];
    for(int i=0; i<n; ++i)
    {
       Matrix[i] = new bool[n];
       Matrix[i][i]=0;
    }

    srand(time(NULL));
    for(int i=0; i<n-1; ++i)
            for(int j=i+1; j<n; ++j)
            {
                    if(p*100>rand()%100)
                          Matrix[i][j]=Matrix[j][i]=1;

                    else
                         Matrix[i][j]=Matrix[j][i]=0;

            }

        return new Graph(Matrix, n);
}

Graph* Graph::copyFromConnectionList(std::vector<Connection> connectionList)
{
    // zakladamy, ze maksymalny indeks wierzcholka
    // jest rowny liczbie wierzcholkow
    int max = 0;
    for(unsigned int i=0; i<connectionList.size()-1; i++) {
        int current = connectionList[i].getMax();
        if(current > max) {
            max = current;
        }
    }

    // tworzymy nowa macierz sasiedztwa
    bool** adjacencyMatrix = new bool*[max];
    for(int i=0; i<max-1; i++)
        adjacencyMatrix[i] = new bool[max];

    // i-ty element connectionList zawiera wierzcholki
    // o numerach firstID i secondID - laczymy je - modyfikujemy
    // odpowiednio utworzona macierz sasiedztwa
    for(unsigned int i=0; i<connectionList.size()-1; i++) {
        int cID_1 = connectionList[i].firstID;
        int cID_2 = connectionList[i].secondID;

        adjacencyMatrix[cID_1][cID_2] = adjacencyMatrix[cID_2][cID_1] = true;
    }

    // zwracamy wskaznik na nowo utworzony graf
    return new Graph(adjacencyMatrix, max);
}

Graph* Graph::copyFromConnectionMatrix(std::vector<std::vector<bool> > connectionMatrix)
{
    // connectionMatrix zawiera connectionMatrix.size() krawedzi
    // oraz connectionMatrix[0].size() wierzcholkow
    const int verticesNumber = connectionMatrix.size();
    const int connectionsNumber = connectionMatrix[0].size();

    // tworzymy wektor, ktory bedzie zawieral wszystkie krawedzie
    std::vector<Connection> connectionList;
    enum ID { first, second };

    // dla kazdej krawedzi sprawdzamy,
    // ktore 2 wierzcholki sa z nia incydentne
    // jezeli dla jakiejs krawedzi jest wiecej niz 2 wartosci
    // roznych od 0, to zostana wziete pod uwage 2 pierwsze
    // jezeli mniej niz 2, to obiekt connection
    // nie zostanie dodany do listy polaczen connectionList
    for(int i=0; i<connectionsNumber-1; i++)
    {
        ID cID = first;
        Connection connection;

        for(int j=0; j<verticesNumber-1; j++)
        {
            if(connectionMatrix[i][j] == true && cID == first)
            {
                connection.firstID = j;
                cID = second;
            }
            else if(connectionMatrix[i][j] == true && cID == second)
            {
                connection.secondID = j;
                connectionList.push_back(connection);
                break;
            }
        }
    }

    // korzystamy z metody copyFromConnectionList przy uzyciu
    // utworzonego wczesniej wektora krawedzi (polaczen)
    return Graph::copyFromConnectionList(connectionList);
}

Graph* Graph::copyFromAdjancencyList(std::vector<std::vector<int> > adjancencyList){
    Graph * result=new Graph(adjancencyList.size());

    for(unsigned i=0;i<adjancencyList.size();i++){
        for(unsigned j=0;j<adjancencyList[i].size();j++){
            result->connectVertices(i,adjancencyList[i][j]);
        }
    }
    return result;
}

int Graph::GetVerticesNumber() const
{
    return this->_verticesNumber;
}
