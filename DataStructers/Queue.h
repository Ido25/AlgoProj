/*
 * submitter: Ido Medina, ID: 316082106
 * This is the Queue .
 * It's implemented with a 2-way linked list of vertexes.
 * */
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
	void enqueue(int v);//this func gets a number, allocates a vertex with the number and inserts it to the queue
	int
	dequeue();//this func returns the data of the queue's head, deletes the queue head and replaces it with the one before him
	int fornt(){ return this->_head->data(); };//this func returns the queue's head data
	int back(){ return this->_tail->data(); };//this func returns the queue's tail data
	int size(){ return this->_size; };//this func returns the queue's size
	bool isEmpty(){ return this->size() == 0; };//this func returns whether the queue is empty or not
	void makeEmpty(){ delete this; };//this func deletes the queue
  
  private:
	int _size;
	Vertex *_head, *_tail;
};
