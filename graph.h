#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
//#include <priority_queue>
using namespace std;
typedef map<string,vector<string>> adjacencyList;

class Graph
{
private:
  adjacencyList m_adjList;
 // long m_time;
  //unordered_set<string> m_visited;
  //string m_startVertex;
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
   //void dfs(string &strKey); 
   //void dfs_impl(string &strKey);
   //void dfs_impl_kosaraju(string &strNode);
   //void dfs_loop_rev();
};
