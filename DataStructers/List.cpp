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
			return true;//We found num :)
		}
		
		curr = curr->getNext();
	}
	
	return false;//We've past all of the nodes and didn't found num
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
void List::insertToHead(int v){
	
	Vertex *vertex = new Vertex(v);
	
	if(this->_head == nullptr){
		this->_head = this->_tail = vertex;
	}
	else{
		vertex->setNext(this->_head);
		this->_head->setPrev(vertex);
		this->_head = vertex;
	}
	this->_size++;
}
void List::insertToTail(int v){
	
	Vertex *vertex = new Vertex(v);
	
	if(this->_head == nullptr){
		this->_head = this->_tail = vertex;
	}
	else{
		vertex->setPrev(this->_tail);
		this->_tail->setNext(vertex);
		this->_tail = vertex;
	}
	this->_size++;
}
Vertex *List::deleteNode(int num){
	
	Vertex *curr = this->_head;
	Vertex *res;
	
	if(this->find(num)){
		while(curr != nullptr){
			if(curr->data() == num){
				if(curr->getPrev() == nullptr){//The list'_s head
					if(curr->getNext() != nullptr){//Checking if it's a 1 Vertex list
						curr->getNext()->setPrev(nullptr);
					}
					this->_head = curr->getNext();
				}
				else if(curr->getNext() == nullptr){//The list's tail. The list's size is necessarily greater than 1
					curr->getPrev()->setNext(nullptr);
					this->_tail = curr->getPrev();
				}
				else{//Somewhere in the middle
					curr->getPrev()->setNext(curr->getNext());
					curr->getNext()->setPrev(curr->getPrev());
				}
				
				this->_size--;
				res = curr->getNext();
				delete curr;
				return res;//returning the node's data
			}
			else{
				curr = curr->getNext();
			}
		}
	}
	
	return nullptr;
}
void List::printAdjList(int u){
	
	static int cnt = 0;
	Vertex *curr = this->_head;
	
	while(curr != nullptr){
		cout << u << " " << curr->data() << " ";
		
		curr = curr->getNext();
	}
}
void List::copyList(List &L){
	
	if(L.getSize() != 0){
		this->_size = L._size;
		this->_head = new Vertex(L.getHead()->data());
		Vertex *currG = L._head->getNext();
		Vertex *currThis = this->_head;
		
		while(currG != nullptr){
			currThis->setNext(new Vertex(currG->data()));
			currThis->getNext()->setPrev(currThis);
			currThis = currThis->getNext();
			currG = currG->getNext();
		}
	}
}

