/*
 * This is the Vertex class, we use it in the List and Queue classes
 * */
#pragma once
#include "../configs.h"

class Vertex{
  public:
	//////////////////CONSTRUCTORS//////////////////
	Vertex() : _data(-1), _next(nullptr), _prev(nullptr){};//Basic constructor for uninitialized vertexes
	Vertex(int data) : _data(data), _next(nullptr), _prev(nullptr){};//constructor for a new node
	Vertex(int data, Vertex *next, Vertex *prev) : _data(data), _next(next), _prev(prev){};
	Vertex(Vertex &v){
		
		this->_data = v._data;
		this->_next = v._next;
		this->_prev = v._prev;
	};//Copy constructor
	
	//////////////////GETTERS//////////////////
	int data(){ return this->_data; };//this func returns the vertex's data
	Vertex *getNext(){ return this->_next; };//this func returns the vertex's next pointer
	Vertex *getPrev(){ return this->_prev; };//this func returns the vertex's prev pointer
	
	//////////////////SETTERS//////////////////
	void setNext(Vertex *next){ this->_next = next; };//this func sets/changes the vertex's next pointer
	void setPrev(Vertex *prev){ this->_prev = prev; };//this func sets/changes the vertex's prev pointer
  
  private:
	int _data;
	Vertex *_next, *_prev;
};
