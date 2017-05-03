#include "dijkastra.h"

ShortestPath :: ShortestPath(string &source, string &destination, Graph &graphRef)
{
  m_source = source;
  m_destination = destination;
  m_graphRef = graphRef;
  m_distVertex.resize(graphRef.size());
  m_distVertex.clear();  
}

void run_impl()
{
  auto vertexItr = m_graphRef.find(m_source);
  if ( vertexItr != m_graphRef.end())
  {
   for (auto listItr : vertexItr->second)
   {
    if      
   }
  }
}
void run()
{  
 for ( auto distItr : m_distVertex )
 {
   distItr->second = 300000;
 }
 auto distItrSource = m_distVertex.find(source);

 if ( distItrSource != m_distVertex.end())
 {
    distItrSource->second = 0;
 }
 run_impl();

}
