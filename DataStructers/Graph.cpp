#include "Graph.h"

Graph::Graph(Graph &G){
	
	this->_size = G._size;
	this->_adj_arr = new List[this->_size];
	this->_t = G._t;
	this->_s = G._s;
	
	for(int i = 1; i < this->_size; i++){
		this->_adj_arr[i].copyList(G._adj_arr[i]);
	}
}
Graph::~Graph(){
	
	this->deleteGraph();
	delete[] this->_adj_arr;
}
void Graph::makeEmptyGraph(int n){
	
	this->_size = n + 1;
	
	if(this->_size != 0){
		this->deleteGraph();
		delete[] this->_adj_arr;
	}
	
	this->_adj_arr = new List[this->_size];
}
void Graph::deleteGraph(){// This func deletes all the graph'_s adj lists
	
	if(this->_size != 0){
		
		for(int i = 1; i < this->_size; i++){//The loop runs from 1 to n
			this->_adj_arr[i].emptyList();
			cout << i << " ";
		}
	}
}
bool Graph::isAdj(int u, int v){
	
	return this->_adj_arr[u].find(v);
}
int Graph::addEdge(int u, int v){
	
	this->_adj_arr[u].insertToHead(new Vertex(v));
	
	if(this->_adj_arr[u].find(v)){
		return 1;
	}
	else{
		return 0;
	}
}
void Graph::removeEdge(int u, int v){
	
	this->_adj_arr[u].deleteNode(v);
}
void Graph::printGraph(){
	
	for(int i = 1; i < this->_size; i++){//The loop runs from 1 to n
		this->_adj_arr[i].printAdjList(i);
	}
	cout << endl;
}
void Graph::readGraph(){
	
	int u, v, counter = 0;
	string f_name;
	fstream fp;
	
	if(this->_size != 0){//Checking whether this graph is already allocated
		this->deleteGraph();
		delete[] this->_adj_arr;
	}
	
	cout << "Please insert file'_s name: " << endl;
	cin >> f_name;
	
	fp.open(f_name);
	if(fp.fail()){
		throw "ERR: opening file";
	}
	
	fp >> this->_size;
	this->_size++;
	this->_adj_arr = new List[this->_size];//Creating the adj list array
	
	fp >> this->_s;
	fp >> this->_t;
	
	while(!fp.eof()){
		fp >> u;
		fp >> v;
		
		this->_adj_arr[u].insertToHead(new Vertex(v));
	}
	
	fp.close();
}
void Graph::makeGt(Graph &Gt){//Creating Gt graph
	
	if(Gt.getSize() != 0){
		Gt.deleteGraph();
		delete[] Gt._adj_arr;
	}
	Gt._size = this->_size;
	Gt._adj_arr = new List[Gt._size];
	
	Gt._s = this->_t;
	Gt._t = this->_s;
	
	for(int i = 1; i < this->_size; i++){
		Vertex *curr = this->_adj_arr[i].getHead();
		
		while(curr != nullptr){
			Gt._adj_arr[curr->data()].insertToHead(new Vertex(i));// inserting the opposite edge to Gt
			
			curr = curr->getNext();
		}
	}
}
