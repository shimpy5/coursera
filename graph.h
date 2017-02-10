#pragma once
#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef map<string,vector<string>> adjacencyList;
class Graph
{
private:
  adjacencyList m_adjList;
public:
  Graph(adjacencyList  &adjList);
  Graph() = default;
  Graph(const Graph &g);
  Graph(const Graph &&g);
  Graph & operator =(const Graph &);
  Graph & operator =(Graph &&);
  
   adjacencyList & getAdjacencyList();
   const vector<string> & getEdgesAt(const string &vertex);
   void setEdgesAt(const string &vertex, vector<string> &vecEdges);
   void display();
   void reverse(); 
   
};
