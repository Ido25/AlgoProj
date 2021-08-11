/*
 * This file contains the algorithms that we need for the main program that are not a part of a class.
 * The BFS is implemented as we learned in class with a Queue and the parents arr
 * */
#pragma once
#include "DataStructers/Graph.h"
#include "DataStructers/Queue.h"
#include "configs.h"

namespace algos{
  //this function receives a Graph G, the s vertex to start running from, a pointer to the parents arr and returns the degrees arr
  int *BFS(Graph &G, int vertex, int *pArr);
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //this function receives a graph and it's degrees arr after the BFS run and it returns the graph after the function changes the graph
  void deleteLongPaths(Graph &Gs, int *dArr);
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //this function receives graph G and an empty graph H and returns changes H to hold all the shortest paths from s to t
  void buildShortestPathsGraph(Graph &G, Graph &H);
}