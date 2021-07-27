#pragma once
#include "DataStructers/Graph.h"
#include "DataStructers/Queue.h"

namespace algos{
  int *BFS(Graph &G, int vertex, int *pArr);
  void deleteLongPaths(Graph &Gs, int *dArr);
  Graph buildShortestPathsGraph(Graph &G);
}


