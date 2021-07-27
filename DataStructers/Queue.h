#pragma once
#include "Vertex.h"

class Queue{
  public:
	//////////////////CONSTRUCTORS//////////////////
	Queue() : _size(0), _head(nullptr), _tail(nullptr){};//Basic constructor for uninitialized vertexes
	Queue(Queue &Q) = delete;
	//////////////////DESTRUCTOR//////////////////
	~Queue();
	//////////////////METHODS//////////////////
	void enqueue(Vertex *v);
	Vertex *dequeue();
	const Vertex &fornt(){ return *this->_head; };
	const Vertex &back(){ return *this->_tail; };
	int size(){ return this->_size; };
	bool isEmpty(){ return this->size() == 0; };
	void makeEmpty(){ delete this; };
  
  private:
	int _size;
	Vertex *_head, *_tail;
};
