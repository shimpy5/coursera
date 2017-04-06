#include <iostream>
#include <fstream>
#include <algorithm>
#include "graph.h"
#include <string.h>
#include <unordered_set>
/*Changing comments for git*/
using namespace std;

Graph::Graph(map<string, vector<string>> &map_AdjList)
{
  m_adjList = map_AdjList;
  m_time = 0;
  m_startVertex = "0";
}

Graph::Graph(const Graph &&ref)
{
  *this = std::move(ref);
}
Graph& Graph:: operator = (const Graph &grRef)
{
 if (this != &grRef)
 {
   m_adjList.clear();
   m_adjList = grRef.m_adjList;
   m_time = grRef.m_time;
   m_visited  = grRef.m_visited;
   m_startVertex = grRef.m_startVertex;
 }
}
Graph& Graph:: operator = (Graph && grRef)
{
  if( this != &grRef)
  {
     m_adjList.clear();
     m_adjList = grRef.m_adjList;
     m_time = grRef.m_time;
     m_visited  = grRef.m_visited ;
     m_startVertex = grRef.m_startVertex;
     grRef.m_adjList.clear();
     grRef.m_time = 0;
     grRef.m_visited .clear();
  }
}
void Graph:: display()
{

 for (auto adjList : m_adjList)
 {
   cout << endl << adjList.first << "=>";
   for( auto vec : adjList.second)
     cout << vec << " "; 
   cout <<endl;
 }
}

void Graph :: dfs_impl(string &strKey)
{
// static unordered_set<string> m_visited Set;
// m_visited Set.resize(m_adjList.size())
 
 auto cmp = [] (long left, long right) { return (left < right); };
 static priority_queue<long, vector<pair<long, string>, decltype(cmp)> pq(cmp); 
  
 auto keyItr = m_adjList.find(strKey);
 if( keyItr != m_adjList.end())
 {
  for( auto val : keyItr.second)
  { 
   auto  ValItr = m_visited.find(val); 
   if( ValItr == m_visited.end())
   {
 	cout << endl << "DFS key not found" << val << endl;
        m_visited.insert(val);
        dfs_impl(val);
   }
  }
  m_time++;
  pq.push(pair<long, string>(m_time, strKey)); 
 }
 else
   cout << endl << "DFS key not found" << endl;
}
void Graph::dfs(string &strKey)
{
  cout << endl << "Starting DFS" << endl;
    
  //dfs_impl(strKey);
}

void Graph :: dfs_impl_kosaraju(string strNode)
{
  m_visited.insert(strNode);
  //static map<string, string> leader;
  m_leader.insert(pair<string,string>p(strNode, startVertex));
  dfs_impl(strNode);
   
}
void DFS_Kosaraju :: dfs_loop_rev()
{
 //static long time = 0;
 //auto cmp = [] (long left, long right) { return (left < right); }
 //static unordered_set<string> m_visited ;
 //priority_queue<long, vector<pair<long, string>, decltype(cmp)> pq(cmp);
 pair<string, vector<string>> pGNode;
 
 for (auto &pGNode : m_graph.getAdjacencyList())
 {
   auto  ValItr = m_visited.find(pGNode.first);
   if(ValItr == m_visited.end())
   {
     m_startVertex = pGNode.first;
     dfs_impl_kosaraju(pGNode.first);
   }
 } 
 
}


adjacencyList & Graph :: getAdjacencyList()
{
  return m_adjList;
}
void Graph:: reverse()
{
  adjacencyList orig_adjacencyList = m_adjList;
  adjacencyList revAdjList;
  for (auto &adjList : orig_adjacencyList)
  {
    for (auto valItem : adjList.second)
    {
      auto keyIndexItr = revAdjList.find(valItem);
      if( keyIndexItr != revAdjList.end())
      {
        (keyIndexItr->second).push_back(adjList.first);
      }
      else
      {
        vector<string> revOutEdges;
        revOutEdges.push_back(adjList.first);
        revAdjList.insert(std::pair<string, vector<string>>(valItem, revOutEdges));
      }
    }
  }
  m_adjList = revAdjList;
}

DFS_Kosaraju :: DFS_Kosaraju(Graph &grRef)
{
  m_graph = grRef;
}


int main(int argc, char *argv [])
{
 cout << "My name is shimpy" << endl;
 ifstream file;
 std:: string line;
 vector<string> strLine; 
 file.open("scc.txt", ios::in);
 while ( !file.eof())
 {
  getline(file, line, '\n');
  strLine.push_back(line);
 }
 map<string, vector<string>> graphList;
 for( auto vec : strLine)
 {
   string strNodeList = vec;
   int index = 0;
   string strKey;
   vector<string> strVal;
   std:: size_t found = strNodeList.find_first_of(" ");
   if (found != std::string::npos)
   {
      strKey = strNodeList.substr(index, found);
      index = found;
//      cout << strKey << endl;
   }   
   if(strKey.length() > 0)
   {
     adjacencyList::iterator itr = graphList.find(strKey);
     
     size_t index1 = strNodeList.find_first_of(" ");
     size_t index2 = strNodeList.find_last_of(" ");
//     cout << "Space Index" << index1 <<endl;
//     cout<< "Return Index" << index2 << endl;
     
   
     if( index1 != std::string::npos && index2 != std::string::npos)
     {
        size_t length = (index2 - 1) - index1;
        std::string val = strNodeList.substr(index1 + 1, length);
	if(itr != graphList.end())
        {
          itr->second.push_back(val);
        }
        else
        {
     	 strVal.push_back(val);
        }
      
      }
      if(!strVal.empty())
      {
          graphList.insert(std::pair<string,vector<string>>(strKey,strVal)); 
      }
   }
 } 
 Graph orig(graphList);
 orig.display();
 orig.reverse();
 orig.display();
 string nodeVal="22";
 orig.dfs(nodeVal);
 orig.dfs_loop_rev();
// orig.display(); 
}

