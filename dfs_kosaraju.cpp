#include <iostream>
#include <set>
#include "dfs_kosaraju.h"

DFS_Kosaraju :: DFS_Kosaraju(Graph &grRef)
{
  m_graph = grRef;
}

void DFS_Kosaraju  :: dfs_impl1(string strKey)
{
  m_visited.insert(strKey);
//  m_leader.insert(pair<string, string> p(m_startVertex,strKey));
  auto itrDFSNode = m_graph.getAdjacencyList().find(strKey);
  
  for ( auto outgoingNodesItr : itrDFSNode->second)
  {
     if(m_visited.find(outgoingNodesItr) == m_visited.end())
     {
         dfs_impl1(outgoingNodesItr);
     }
  }
  m_time++;
  pqNode node(m_time, strKey);
  m_pq.push(node);
}

void DFS_Kosaraju  :: dfs_impl2(string strkey)
{
  m_visited.insert(strkey);
  m_leader.insert(pair<string, string> (m_startVertex, strkey));
  auto itrDFSNode = m_graph.getAdjacencyList().find(strkey);
  
  for (auto outgoingNodesItr : itrDFSNode->second)
  {
     if(m_visited.find(outgoingNodesItr) == m_visited.end())
     {
         dfs_impl2(outgoingNodesItr);
     }
  }
}

void DFS_Kosaraju :: dfs_loop1()
{
 pair<string, vector<string>> pRevGNode;
 Graph grCopy = m_graph;
 grCopy.reverse(); 
 for (auto &pRevGNode : grCopy.getAdjacencyList())
 {
   auto  ValItr = m_visited.find(pRevGNode.first);

   if(ValItr == m_visited.end())
   {
     dfs_impl1(pRevGNode.first);
   }
 } 
} 

void DFS_Kosaraju  :: dfs_loop2()
{
  m_visited.clear();
  pair<string, vector<string>> pGNode;
 
  DFS_Kosaraju::pqNode pNode = m_pq.top();
 
  for ( ; m_graph.getAdjacencyList().find(pNode.strKey) != m_graph.getAdjacencyList().end() && m_pq.empty() == false; )
  {
    m_pq.pop();
    auto gNodeItr = m_visited.find(pGNode.first);
    if (gNodeItr == m_visited.end())
    {
    	m_startVertex = pNode.strKey;
    	dfs_impl2(pNode.strKey);
    }
    m_pq.pop();
    pNode = m_pq.top();
  }

}

int DFS_Kosaraju :: strongComponentCount()
{
 set<string>countSet;
 for (auto leaderItr : m_leader)
 {
    countSet.insert(leaderItr.first);
 }
 return countSet.size();
}

