#include "Queue.h"

Queue::~Queue(){
	
	for(Vertex *curr = this->_tail; this->_size > 0; this->_size--){
		Vertex *tmp = curr->getNext();
		delete curr;
		curr = tmp;
	}
}
void Queue::enqueue(Vertex *v){
	
	if(this->_size == 0){
		this->_head = this->_tail = v;
	}
	else{
		this->_tail->setPrev(v);
		v->setNext(this->_tail);
		v->setPrev(nullptr);
		this->_tail = v;
	}
	this->_size++;
}
Vertex *Queue::dequeue(){
	
	Vertex *res = this->_head;
	
	if(this->_size == 1){
		this->_head = this->_tail = nullptr;
	}
	else if(this->_size > 1){
		this->_head = this->_head->getPrev();
		this->_head->setNext(nullptr);
	}
	
	if(this->_size > 0)
		this->_size--;
	
	return res;
}
