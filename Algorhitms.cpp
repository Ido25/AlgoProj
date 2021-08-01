#include "Algorhitms.h"

namespace algos{
  int *BFS(Graph &G, int vertex, int *pArr){
	
	  if(G.getSize() <= vertex){//checking that the vertex is in the graph's vertexes range
		  return nullptr;
	  }
	
	  int *dArr = new int[G.getSize()], cnt = 0;
	  Queue Q;
	
	  for(int i = 1; i < G.getSize(); i++){
		  dArr[i] = INFINITY_DEGREE;//initalizing all the degrees to infinity
		  pArr[i] = NULL_PARENT;//initalizing all the parents to NULL
	  }
	
	  Q.enqueue(vertex);
	  dArr[vertex] = 0;
	  pArr[vertex] = vertex;
	
	  while(!Q.isEmpty()){//BFS main loop
		  int p_vertex = Q.dequeue();//The parent vertex
		  Vertex *curr = G.getAdjList(p_vertex).getHead();
		
		  while(curr != nullptr){
			  if(dArr[curr->data()] == INFINITY_DEGREE){
				  dArr[curr->data()] = dArr[p_vertex] + 1;
				  pArr[curr->data()] = p_vertex;
				  Q.enqueue(curr->data());
			  }
			
			  curr = curr->getNext();
		  }
	  }
	
	  return dArr;
  }
  void deleteLongPaths(Graph &Gs, int *dArr){//This function deletes all the edges (u,v) that doesn't make
	  //d[u] + 1 = d[v] after the BFS run
	  
	  for(int i = 1; i < Gs.getSize(); i++){//main loop
		  if(!Gs.getAdjList(i).isEmpty()){
			  Vertex *curr = Gs.getAdjList(i).getHead();//getting the current vertex list
			  
			  while(curr != nullptr){
				  if(dArr[i] + 1 != dArr[curr->data()]){//checking if the edge stands in the condition
					  int tmp = curr->data();
					  curr = Gs.removeEdge(i, curr->data());
				  }
				  else{
					  curr = curr->getNext();
				  }
			  }
		  }
	  }
  }
  void buildShortestPathsGraph(Graph &G, Graph &H){//main algorithm function
	  
	  Graph Gs(G), Gst;
	  int *pArr = new int[G.getSize()], *GstParr, *GstDarr;
	  int *dArr = BFS(Gs, Gs.getS(), pArr);//BFS run on Gs graph (which is a copy of G)
	  
	  deleteLongPaths(Gs, dArr);//deleting long paths as explained in the function above
	  
	  Gs.makeGt(Gst);//making Gs transpose graph- Gst
	  
	  GstParr = new int[Gst.getSize()];
	  GstDarr = BFS(Gst, Gst.getS(), GstParr);//BFS run on Gst
	  
	  for(int i = 1; i < Gst.getSize(); i++){//deleting all the edges that arent reachable from Gst
		  if(GstDarr[i] == INFINITY_DEGREE){
			  Gst.getAdjList(i).emptyList();
		  }
	  }//Gst is Ht now
	  
	  Gst.makeGt(H);
  }
}

