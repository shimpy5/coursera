#include <iostream>
#include <fstream>
#include <algorithm>
#include "graph.h"
#include <string.h>
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
 adjacencyList::iterator itr = m_adjList.begin();
 for( ; itr != m_adjList.end(); itr++ );
 {
   cout << "Key \t" << itr->first << "Value \t";
   for ( auto vec : itr->second)
   { 
    cout << vec << " ";
   }
   cout << endl;
 }
}

void Graph:: reverse()
{
  Graph revg = new Graph();
  for (auto adjList : m_adjList)
  {
    for (auto valItem : adjList)
    {
      size_t keyIndex = revg.findkey(valItem);
      if( keyIndex != std::string::npos)
      {
        revg[keyIndex].push_back(adjList->first);
      }
      else
      {
        revg.insert(std::pair(valItem, adjList->first);
      }
    }
  }
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
     cout << "Space Index" << index1 <<endl;
     cout<< "Return Index" << index2 << endl;
     
   
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
}

 for (auto adjList : graphList)
 {
   cout << endl << adjList.first << "=>";
   for( auto vec : adjList.second)
     cout << vec << " "; 
   cout <<endl;
 }
  
}
