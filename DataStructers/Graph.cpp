#include "Graph.h"

Graph::Graph(Graph &G){//copy constructor
	
	if(G.getSize() != 0){
		this->_size = G._size;
		this->_adj_arr = new List[this->_size];
		this->_t = G._t;
		this->_s = G._s;
		
		for(int i = 1; i < this->_size; i++){
			if(!G.getAdjList(i).isEmpty())
				this->_adj_arr[i].copyList(G._adj_arr[i]);
		}
	}
}
Graph::~Graph(){
	
	this->deleteGraph();
	delete[] this->_adj_arr;
}
void Graph::makeEmptyGraph(int n){
	
	if(this->_size != 0 && this->_adj_arr != nullptr){//checking whether the graph is already allocated
		this->deleteGraph();
		delete[] this->_adj_arr;
	}
	
	this->_size = n + 1;
	this->_adj_arr = new List[this->_size];
}
List &Graph::getAdjList(int u){
	
	if(u >= this->_size){ throw "err"; };
	return this->_adj_arr[u];
};
void Graph::deleteGraph(){// This func deletes all the graph'_s adj lists
	
	if(this->_size != 0){
		
		for(int i = 1; i < this->_size; i++){//The loop runs from 1 to n
			this->_adj_arr[i].emptyList();
		}
	}
}
bool Graph::isAdj(int u, int v){
	
	if(this->_size <= u && this->_size <= v){
		return this->_adj_arr[v].find(u) || this->_adj_arr[u].find(v);
	}
	
	return false;
}
int Graph::addEdge(int src, int dst){
	
	if(this->_size <= src && this->_size <= dst){
		this->_adj_arr[src].insertToHead(dst);
		
		if(this->_adj_arr[src].find(dst)){
			return 1;
		}
		else{
			return 0;
		}
	}
	
	return 0;
}
Vertex *Graph::removeEdge(int src, int dst){
	
	if(src < this->_size && dst < this->_size && !this->_adj_arr[src].isEmpty())
		return this->_adj_arr[src].deleteNode(dst);
	
	return nullptr;
}
void Graph::printGraph(){
	
	for(int i = 1; i < this->_size; i++){//The loop runs from 1 to n
		this->_adj_arr[i].printAdjList(i);
	}
	cout << endl;
}
void Graph::readGraph(){
	
	int u, v, size;
	fstream fp("t1Errorin.txt");
	
	if(this->_size != 0){//Checking whether this graph is already allocated
		this->deleteGraph();
		delete[] this->_adj_arr;
	}
	
	fp >> size;//getting graph's size
	
	if(size <= 0){ throw "err"; }
	
	this->_size = size;
	this->_size++;
	this->_adj_arr = new List[this->_size];//Creating the adj list array
	
	fp >> u >> v;//getting s and t
	
	if(this->inRange(u) && this->inRange(v)){
		this->_s = u;
		this->_t = v;
	}
	else{ throw "err"; }
	
	while(!cin.eof()){//getting edges
		fp >> u >> v;
		if(this->inRange(u) && this->inRange(v)){
			this->_adj_arr[u].insertToHead(v);
		}
		else{
			throw "err";
		}
	}
}
void Graph::makeGt(Graph &Gt){//Creating Gt graph
	
	if(Gt.getSize() != 0){//checking whether the graph is already allocated
		Gt.deleteGraph();
		delete[] Gt._adj_arr;
	}
	Gt._size = this->_size;
	Gt._adj_arr = new List[Gt._size];
	
	Gt._s = this->_t;
	Gt._t = this->_s;
	
	for(int i = 1; i < this->_size; i++){//running on the vertexes
		Vertex *curr = this->_adj_arr[i].getHead();
		
		while(curr != nullptr){
			Gt._adj_arr[curr->data()].insertToHead(i);// inserting the opposite edge to Gt
			
			curr = curr->getNext();
		}
	}
}
void Graph::printBFSGraph(int s){//printing the graph by it's BFS pass
	
	int cnt = 0;
	Queue Q;
	Q.enqueue(s);
	
	while(!Q.isEmpty()){
		int p_vertex = Q.dequeue();//The parent vertex
		Vertex *curr = this->_adj_arr[p_vertex].getHead();
		
		while(curr != nullptr){
			cout << ++cnt << ": " << p_vertex << " " << curr->data() << " " << endl;
			Q.enqueue(curr->data());
			
			curr = curr->getNext();
		}
	}
}
