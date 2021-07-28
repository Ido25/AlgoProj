#include "Queue.h"

Queue::~Queue(){
	
	for(Vertex *curr = this->_tail; this->_size > 0; this->_size--){
		Vertex *tmp = curr->getNext();
		delete curr;
		curr = tmp;
	}
}
void Queue::enqueue(int v){
	
	Vertex *vertex = new Vertex(v);
	
	if(this->_size == 0){
		this->_head = this->_tail = vertex;
	}
	else{
		this->_tail->setPrev(vertex);
		vertex->setNext(this->_tail);
		vertex->setPrev(nullptr);
		this->_tail = vertex;
	}
	this->_size++;
}
int Queue::dequeue(){
	
	Vertex *res = this->_head;
	int vertex_data;
	
	if(this->_size == 1){
		this->_head = this->_tail = nullptr;
	}
	else if(this->_size > 1){
		this->_head = this->_head->getPrev();
		this->_head->setNext(nullptr);
	}
	
	if(this->_size > 0)
		this->_size--;
	
	vertex_data = res->data();
	delete res;
	
	return vertex_data;
}
