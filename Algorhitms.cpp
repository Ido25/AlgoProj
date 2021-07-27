#include "Algorhitms.h"

namespace algos{
  int *BFS(Graph &G, int vertex, int *pArr){
	  
	  int *dArr = new int[G.getSize()], cnt = 0;
	  Queue Q;
	  
	  for(int i = 1; i < G.getSize(); i++){
		  dArr[i] = -1;//initalizing all the degrees to infinity
		  pArr[i] = -1;//initalizing all the parents to NULL
	  }
	  
	  Q.enqueue(new Vertex(vertex));
	  dArr[vertex] = 0;
	  pArr[vertex] = vertex;
	  
	  while(!Q.isEmpty()){
		  Vertex *p_vertex = Q.dequeue();//The parent vertex
		  List lst;
		  lst = G.getAdjList(p_vertex->data());
		  Vertex *curr = lst.getHead();
		  
		  while(curr != nullptr){
			  if(dArr[curr->data()] == -1){
				  dArr[curr->data()] = dArr[p_vertex->data()] + 1;
				  pArr[curr->data()] = p_vertex->data();
				  Q.enqueue(new Vertex(curr->data()));
			  }
			  
			  curr = curr->getNext();
		  }
		  
		  delete p_vertex;
	  }
	  
	  for(int i = 0; i < G.getSize(); i++){
		  if(dArr[i] == -1)
			  cout << i << ", ";
	  }
	  
	  return dArr;
  }
  void deleteLongPaths(Graph &Gs, int *dArr){
	  
	  for(int i = 1; i < Gs.getSize(); i++){
		  List lst;
		  lst = Gs.getAdjList(i);
		  Vertex *curr = lst.getHead();
		  
		  while(curr != nullptr){
			  if(dArr[i] + 1 != dArr[curr->data()]){
				  cout << "Removing: " << i << ": " << dArr[i] << ", " << curr->data() << ": " << dArr[curr->data()]
					   << endl;
				  Gs.removeEdge(i, curr->data());
				  curr = curr->getNext();
			  }
		  }
	  }
  }
  Graph buildShortestPathsGraph(Graph &G){
	  
	  Graph Gs(G), Gst;
	  int *pArr = new int[G.getSize()];
	  int *dArr = BFS(G, G.getS(), pArr);
	  
	  deleteLongPaths(Gs, dArr);
	  //TODO: change STL so it will take numbers instead of vertexs
	  //TODO: change BFS to without pArr and change loop so it'll run on the graph and not on the pArr
	  Gs.makeGt(Gst);
	  
	  int *GstParr = new int[Gst.getSize()];
	  int *GstDarr = BFS(Gst, G.getT(), GstParr), cnt = 0;
	  
	  for(int i = 1; i < Gst.getSize(); i++){
		  int parent = GstParr[i];
		  
		  if(dArr[i] == -1){
			  cout << ++cnt << " ";
			  Gst.removeEdge(parent, i);
		  }
	  }
	  
	  Graph Ht(Gst);
	  Gst.makeGt(Ht);
	  return Ht;//Which is now H
  }
}

