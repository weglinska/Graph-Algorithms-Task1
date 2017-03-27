#include "filemanager.h"

void FileManager::writeToFile(Graph* graph,std::string path)
{
	bool** Matrix = graph->getAdjacencyMatrix();
	int verticesNumber = graph->getVerticesNumber();

    std::ofstream file(path.c_str());

	if(file.is_open())
	{
		file << verticesNumber;
		file << " ";

		for(int i=0; i<verticesNumber; i++)
		{
			for(int j=0; j<verticesNumber; j++)
			{
				file << Matrix[i][j];
				file << " ";
			}
		}
	}

	file.close();
}

Graph* FileManager::readFromFile(std::string path)
{

	bool** Matrix;
	int verticesNumber;

    std::ifstream file(path.c_str());

    if(!file.is_open()){
        return NULL;
    }

    file >> verticesNumber;
		
    Matrix = new bool*[verticesNumber];
    for(int i=0; i<verticesNumber; i++){
        Matrix[i] = new bool[verticesNumber];
    }

    for(int i=0; i<verticesNumber; i++)
    {
        for(int j=0; j<verticesNumber; j++)
        {
            file >> Matrix[i][j];
        }
    }


	file.close();

	return new Graph(Matrix, verticesNumber);
}
