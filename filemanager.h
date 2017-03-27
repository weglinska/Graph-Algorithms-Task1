#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "graph.h"
#include <fstream>

class FileManager{
	public:
        static void writeToFile(Graph* graph,std::string path);
        static Graph* readFromFile(std::string path);
};

#endif
