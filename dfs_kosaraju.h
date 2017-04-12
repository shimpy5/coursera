#pragma once
#include <string>
#include <iostream>
#include <map>
#include <unordered_set>
#include <queue>
#include "graph.h"
using namespace std;
class DFS_Kosaraju
{
private:
  struct pqNode
  {
    long time;
    string strKey;
    pqNode(long &ltime, string &strKeyRef)
    {
      time = ltime;
      strKey = strKeyRef;
    }
  };
  struct pqNodeCompare
  {
    bool operator () (pqNode &p1, pqNode &p2)
    {
       if(p1.time < p2.time)
           return true;
       return false;
    }

  };
  Graph m_graph;
  long m_time;
  unordered_set<string> m_visited;
  string m_startVertex;
  priority_queue <pqNode, vector<pqNode>, pqNodeCompare> m_pq;
  multimap<string, string> m_leader;
  void dfs_loop1();
  void dfs_loop2();
  void dfs_impl1(string strKey);
  void dfs_impl2(string strKey);
  
public:
  DFS_Kosaraju(Graph &gr);
  //run();
  int strongComponentCount();
};
