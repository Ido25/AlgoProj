#include "Algorhitms.h"

namespace algos{
  int *BFS(Graph &G, int vertex, int *pArr){
	
	  int *dArr = new int[G.getSize()], cnt = 0;
	  Queue Q;
	
	  for(int i = 1; i < G.getSize(); i++){
		  dArr[i] = -1;//initalizing all the degrees to infinity
		  pArr[i] = -1;//initalizing all the parents to NULL
	  }
	
	  Q.enqueue(vertex);
	  dArr[vertex] = 0;
	  pArr[vertex] = vertex;
	
	  while(!Q.isEmpty()){
		  int p_vertex = Q.dequeue();//The parent vertex
		  Vertex *curr = G.getAdjList(p_vertex).getHead();
		
		  while(curr != nullptr){
			  if(dArr[curr->data()] == -1){
				  dArr[curr->data()] = dArr[p_vertex] + 1;
				  pArr[curr->data()] = p_vertex;
				  Q.enqueue(curr->data());
			  }
			
			  curr = curr->getNext();
		  }
	  }
	  
	  return dArr;
  }
  void deleteLongPaths(Graph &Gs, int *dArr){
	  
	  for(int i = 1; i < Gs.getSize(); i++){
		  if(!Gs.getAdjList(i).isEmpty()){
			  Vertex *curr = Gs.getAdjList(i).getHead();
			
			  while(curr != nullptr){
				  if(dArr[i] + 1 != dArr[curr->data()]){
					  curr = Gs.removeEdge(i, curr->data());
				  }
				  else{
					  curr = curr->getNext();
				  }
			  }
		  }
	  }
  }
  void buildShortestPathsGraph(Graph &G, Graph &res){
	  
	  Graph Gs(G), Gst;
	  int *pArr = new int[G.getSize()], *GstParr, *GstDarr;
	  int *dArr = BFS(Gs, Gs.getS(), pArr);
	
	  deleteLongPaths(Gs, dArr);
	  
	  Gs.makeGt(Gst);

	  
	  GstParr = new int[Gst.getSize()];
	  GstDarr = BFS(Gst, Gst.getS(), GstParr);
	
	  for(int i = 1; i < Gst.getSize(); i++){
		  if(GstDarr[i] == -1){
			  Gst.getAdjList(i).emptyList();
		  }
		  /*  if(!Gst.getAdjList(i).isEmpty()){
				Vertex *curr = Gst.getAdjList(i).getHead();
				
				while(curr != nullptr){
					if(GstDarr[curr->data()] == -1){
						cout << "Removing- (" << i << "," << curr->data() << ")" << endl;
						curr = Gst.removeEdge(i, curr->data());
					}
					else{
						curr = curr->getNext();
					}
				}
			}*/
	  }
	
	  Gst.makeGt(res);
  }
}

