#pragma once
#include <iostream>
#include "Graph.h"
class ShortestPath
{
public:
   ShortestPath(string source , string destination, Graph &graphRef);
   void run();
private:
   unordered_map<string, int> mapChildCount;
   unordered_map<string, int> distVertex;
   Graph &m_graphRef;
   
};
