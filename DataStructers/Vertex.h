#pragma once
#include "../configs.h"

class Vertex{
  public:
	//////////////////CONSTRUCTORS//////////////////
	Vertex() : _data(-1), _next(nullptr), _prev(nullptr){};//Basic constructor for uninitialized vertexes
	Vertex(int data) : _data(data), _next(nullptr), _prev(nullptr){};
	Vertex(int data, Vertex *next, Vertex *prev) : _data(data), _next(next), _prev(prev){};
	Vertex(Vertex &v){
		
		this->_data = v._data;
		this->_next = v._next;
		this->_prev = v._prev;
	};//Copy constructor
	
	//////////////////GETTERS//////////////////
	int data(){ return this->_data; };
	Vertex *getNext(){ return this->_next; };
	Vertex *getPrev(){ return this->_prev; };
	
	//////////////////SETTERS//////////////////
	void setNext(Vertex *next){ this->_next = next; };
	void setPrev(Vertex *prev){ this->_prev = prev; };
  
  private:
	int _data;
	Vertex *_next, *_prev;
};
