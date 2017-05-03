#pragma once
#include <iostream>
#include "Graph.h"
class Vertex
{
 public:
   int getVertexId();
   int getWeight();
   bool operator() (Vertex v1, Vertex v2)
   {
     return (v1.getWeight() < v2.getWeight());
   }
 private:
   int vertexId;
   int weight;
};
class WGraph
{
 public:
  WGraph(int vertex[], int n, list<Vertex> vert);
  list<Vertex> & getAdjacencyList();
  void setAdjacencyListAt(int , list<Vertex>);
 private:
  unordered_map<int, list<Vertex>> m_wgraph; 
};

class ShortestPath
{
public:
   ShortestPath(string source , string destination, Graph &graphRef);
   void run();
private:
   unordered_map<string, int> mapChildCount;
   unordered_map<string, int> distVertex;
   priority_queue<Vertex, vector<Vertex>> m_pq;
   WGraph &m_graphRef;
   
};
