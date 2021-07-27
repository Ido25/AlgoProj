#pragma once
#include "List.h"

class Graph{
  public:
	//////////////////CONSTRUCTORS//////////////////
	Graph() : _size(0), _t(-1), _s(-1){ this->_adj_arr = nullptr; };
	Graph(int n) : _size(n + 1), _t(-1),
				   _s(-1){ this->_adj_arr = new List[n]; };//we put n + 1 because the vertex's range is 1-n
	Graph(Graph &G);
	//////////////////DESTRUCTOR//////////////////
	~Graph();
	//////////////////METHODS//////////////////
	void makeEmptyGraph(int n);
	bool isAdj(int u, int v);
	List &getAdjList(int u){ return this->_adj_arr[u]; };
	int addEdge(int u, int v);
	int getSize(){ return this->_size; };
	int getS(){ return this->_s; };
	int getT(){ return this->_t; };
	void removeEdge(int u, int v);
	void readGraph();
	int isEmpty(){ return this->_size == 0 ? 1 : 0; };
	void printGraph();
	void makeGt(Graph &Gt);
  private:
	int _size;
	List *_adj_arr;
	int _t, _s;
	void deleteGraph();
};

