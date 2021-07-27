#include "List.h"

List::List(List &L){
	
	this->copyList(L);
}
List::~List(){
	
	if(this->_size != 0){
		this->emptyList();
	}
}
bool List::find(int num){
	
	Vertex *curr = this->_head;
	
	while(curr != nullptr){
		if(curr->data() == num){
			return true;//We found the num
		}
		
		curr = curr->getNext();
	}
	
	return false;//We've past all of the nodes and didn'_t found num
}
void List::emptyList(){
	
	Vertex *curr = this->_head;
	
	while(curr != nullptr){
		Vertex *tmp = curr->getNext();
		
		delete curr;
		curr = tmp;
	}
	
	this->_head = this->_tail = nullptr;
	this->_size = 0;
}
void List::insertToHead(Vertex *v){
	
	if(this->_head == nullptr){
		this->_head = this->_tail = v;
	}
	else{
		v->setNext(this->_head);
		this->_head->setPrev(v);
		this->_head = v;
	}
	this->_size++;
}
void List::insertToTail(Vertex *v){
	
	if(this->_head == nullptr){
		this->_head = this->_tail = v;
	}
	else{
		v->setPrev(this->_tail);
		this->_tail->setNext(v);
		this->_tail = v;
	}
	this->_size++;
}
void List::deleteNode(int num){
	
	Vertex *curr = this->_head;
	
	while(curr != nullptr){
		if(curr->data() == num){
			if(curr->getPrev() == nullptr){//The list'_s head
				if(curr->getNext() != nullptr){//Checking if it'_s a 1 Vertex list
					curr->getNext()->setPrev(nullptr);
				}
				this->_head = curr->getNext();
			}
			else if(curr->getNext() == nullptr){//The list'_s tail. The list'_s size is necessarily greater than 1
				curr->getPrev()->setNext(nullptr);
			}
			else{//Somewhere in the middle
				curr->getPrev()->setNext(curr->getNext());
				curr->getNext()->setPrev(curr->getPrev());
			}
			
			delete curr;
			return;
		}
		
		curr = curr->getNext();
	}
}
void List::printAdjList(int u){
	
	Vertex *curr = this->_head;
	
	while(curr != nullptr){
		cout << "(" << u << "," << curr->data() << "), ";
		
		curr = curr->getNext();
	}
}
void List::copyList(List &L){
	
	this->_size = L._size;
	this->_head = new Vertex(L._head->data());
	Vertex *currG = L._head->getNext();
	Vertex *currThis = this->_head;
	
	while(currG != nullptr){
		currThis->setNext(new Vertex(currG->data()));
		currThis->getNext()->setPrev(currThis);
		currThis = currThis->getNext();
		currG = currG->getNext();
	}
}

