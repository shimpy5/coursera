#pragma once
#include <string>
#include <iostream>
#include <map>
#include <unordered_set>
#include <queue>
#include <map>
#include "graph.h"
using namespace std;
class DFS_Kosaraju
{
private:
  struct pqNode
  {
    long time;
    string strKey;
  };
  Graph m_graph;
  long m_time;
  unordered_set<string> m_visited;
  string m_startVertex;
  priority_queue <pqNode> m_pq;
  multi_map<string, string> m_leader;
  void dfs_loop1();
  void dfs_loop2();
  void dfs_impl1(string strKey);
  void dfs_impl2(string strKey);
   
public:
  DFS_Kosaraju(Graph &gr);
  run();
};
