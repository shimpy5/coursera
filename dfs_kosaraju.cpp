#include <iostream>
#include <set>
#include "dfs_kosaraju.h"
#include <algorithm>
int counter_leader_members = 0;
bool startVertexOne = false;
int multi_map_size = 0;
DFS_Kosaraju :: DFS_Kosaraju(Graph &grRef)
{
  m_graph = grRef;
}

void DFS_Kosaraju  :: dfs_impl1(string strKey)
{
  m_visited.insert(strKey);
//  m_leader.insert(pair<string, string> p(m_startVertex,strKey));
 auto itrDFSNode = m_graph.getAdjacencyList().find(strKey);
 if(itrDFSNode != m_graph.getAdjacencyList().end())
 { 
  for ( auto outgoingNodesItr : itrDFSNode->second)
  {
     if(m_visited.find(outgoingNodesItr) == m_visited.end())
     {
         dfs_impl1(outgoingNodesItr);
     }
  }
 }
  m_time++;
  pqNode node(m_time, strKey);
  m_pq.push(node);
}

void DFS_Kosaraju  :: dfs_impl2(string strkey)
{
  m_visited.insert(strkey);
  //counter_leader_members++;
  if(startVertexOne)
  {
    cout << endl << "DFS Keys are " << strkey << endl;
  }
  //m_leader.insert(pair<string, string> (m_startVertex, strkey));
  auto itrDFSNode = m_graph.getAdjacencyList().find(strkey);
  if(itrDFSNode != m_graph.getAdjacencyList().end())
  {
    counter_leader_members++;
  m_leader.insert(pair<string, string> (m_startVertex, strkey));
   for (auto outgoingNodesItr : itrDFSNode->second)
   {
     if(m_visited.find(outgoingNodesItr) == m_visited.end())
     {
         dfs_impl2(outgoingNodesItr);
     }
   }
 }
}

void DFS_Kosaraju :: dfs_loop1()
{
 pair<string, vector<string>> pRevGNode;
 m_graph.reverse();
// m_graph.display();
 cout << endl <<endl;
 //getchar();
 m_visited.clear();
 for (auto &pRevGNode : m_graph.getAdjacencyList())
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
  m_graph.reverse();
//  m_graph.display();
  //getchar();
  pair<string, vector<string>> pGNode;
 
  DFS_Kosaraju::pqNode pNode = m_pq.top();
  
  /*for ( ; m_pq.empty() == false;)
  {
    cout << "The nodes in prioirity queue are:   ";
    cout << pNode.strKey <<endl;
    getchar();
    m_pq.pop();
    pNode = m_pq.top(); 
  }*/
   
 vector<int> vec(10);
  for ( ; m_pq.empty() == false; )
  {
   auto itrFreqNode = m_graph.getAdjacencyList().find(pNode.strKey);

   if( itrFreqNode != m_graph.getAdjacencyList().end())
   {
    auto gNodeItr = m_visited.find(itrFreqNode->first);
    if (gNodeItr == m_visited.end())
    {
    	m_startVertex = pNode.strKey;
        startVertexOne = false;
        if ( m_startVertex == "1")
        {
           startVertexOne = true;
    	   dfs_impl2(pNode.strKey);
        }
        else
        {
            dfs_impl2(pNode.strKey);
        }
        cout << endl << "The start vertex is  " << m_startVertex << " count of members is  " << counter_leader_members;
        cout << endl;
        vec.push_back(counter_leader_members);
        multi_map_size += counter_leader_members;
        counter_leader_members = 0;
    }
   }
    m_pq.pop();
    pNode = m_pq.top();
  }

 cout << "Multimap size is " << m_leader.size();
 cout << "Total members are " << multi_map_size;
 sort(vec.begin(), vec.end());
 cout << " Vec scc are:" <<endl;
 for ( auto vecItr : vec)
 {
   cout << vecItr << endl;
 }
}

int DFS_Kosaraju :: strongComponentCount()
{
 struct SortCompare {
 bool operator() (int i , int j)
 {
   return (i > j);
 } 
}sc;
 map<string, int>countMap;
 vector<int> largesccvec;
 //priority_queue<int> largescc;
 cout << "Multimap size is " << m_leader.size();
 for (auto leaderItr : m_leader)
 {
    //countSet.insert(leaderItr.first);
    //cout << endl << "Counting elements per key" << leaderItr.first<< "==>";
    int elemCount = m_leader.count(leaderItr.first);
    //cout << elemCount << endl;
     countMap.insert(make_pair(leaderItr.first, elemCount));
 }
 for ( auto elemCountItr : countMap)
 {
    //cout << "Size of scc are" << elemCountItr.second;
    largesccvec.push_back(elemCountItr.second);
 }
 sort(largesccvec.begin(), largesccvec.end(), sc);
 int counter = 0;
 cout << "Top 5 SSCC sizes are:" << endl;
 auto itrLarge = largesccvec.begin();
 while(counter < 5)
 {
    cout << *itrLarge << endl;
    counter++;
    itrLarge++;
 }
 return 0;
}
int dfscount = 0;
int keycount = 0;
void resetdfscount()
{
  dfscount = 0;
}
void DFS_Kosaraju :: plaindfs(string strKey)
{
 auto itrG = m_graph.getAdjacencyList().find(strKey);
 
   dfscount++;
   cout << "DFS keys are " << strKey << endl;
   m_visited.insert(strKey);
 if( itrG != m_graph.getAdjacencyList().end())
 {
   for( auto itrList : itrG->second)
   {
      if( m_visited.find(itrList) == m_visited.end())
          plaindfs(itrList);
   }
 }
 else
 {
   cout << endl << "The keys that do not have adjacency list" << strKey << endl;
   keycount++;
 }
 cout << "Key count without adjacency list is" << keycount <<endl;
}
