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
	void enqueue(int v);
	int dequeue();
	int fornt(){ return this->_head->data(); };
	int back(){ return this->_tail->data(); };
	int size(){ return this->_size; };
	bool isEmpty(){ return this->size() == 0; };
	void makeEmpty(){ delete this; };
  
  private:
	int _size;
	Vertex *_head, *_tail;
};
