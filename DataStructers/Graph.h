/*
 * submitter: Ido Medina, ID: 316082106
 * This is the graph class
 * It's implemented by an array of Lists.
 * */
#pragma once
#include "List.h"
#include "Queue.h"

class Graph{
  public:
	//////////////////CONSTRUCTORS//////////////////
	Graph() : _size(0), _t(-1), _s(-1){ this->_adj_arr = nullptr; };//default constructor
	Graph(int n) : _size(0), _t(-1),//making an empty graph
				   _s(-1){ this->makeEmptyGraph(n); };//we put n + 1 because the vertex's range is 1-n
	Graph(Graph &G);//copy constructor
	//////////////////DESTRUCTOR//////////////////
	~Graph();
	//////////////////METHODS//////////////////
	void makeEmptyGraph(int n);//this func receives an int an builds an empty graph with n vertex's
	bool isAdj(int u, int v);//this func gets 2 vertexes and return whether there is an edge between them or not
	List &getAdjList(int u);//this func receives a vertex's number and returns it's adj list
	int addEdge(int src, int dst);//this func gets a source and destination vertexes and inserts an edge between them
	int getSize(){ return this->_size; };//this func returns the graph's size
	int getS(){ return this->_s; };//this func returns the graph's s value
	int getT(){ return this->_t; };//this func returns the graph's t value
	Vertex *removeEdge(int src,
					   int dst);//this func receives an edge, deletes the edge and returns the next edge in the adj list
	void readGraph();//this func reads the graph data and size from stdin
	int isEmpty(){ return this->_size == 0 ? 1 : 0; };//this func returns whether the graph is empty or not
	void printGraph();//this func prints the graph
	void makeGt(Graph &Gt);//this graphs gets a graph G and builds the transpose graph of it- Gt
	void printBFSGraph(int s);//this func is printing the graph by it's BFS pass from vertex s
	bool inRange(int v){
		
		return 0 < v && v < this->_size;
	}//this func receives a vertex and checks if it's in the graph range
  private:
	int _size;
	List *_adj_arr;
	int _t, _s;
	void deleteGraph();
};

