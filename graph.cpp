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
 }
}
Graph& Graph:: operator = (Graph && grRef)
{
  if( this != &grRef)
  {
     m_adjList.clear();
     m_adjList = grRef.m_adjList;
     grRef.m_adjList.clear();
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
 unordered_set<string> visitedSet;
 //visitedSet.resize(m_adjList.size())
 auto keyItr = m_adjList.find(strKey);
 if( keyItr != m_adjList.end())
 {
 vector<string> strAdjList = keyItr->second;
 for( auto val : strAdjList)
 {	
   auto visitedValItr = visitedSet.find(val); 
   if( visitedValItr != visitedSet.end())
   {
 	cout << endl << "DFS key found" << val << endl;
        visitedSet.insert(val);
        dfs_impl(val);
   }
 }
 }
 else
   cout << endl << "DFS key not found" << endl;
}
void Graph::dfs(string &strKey)
{
  dfs_impl(strKey);
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
      cout << strKey << endl;
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
// orig.display(); 
}

