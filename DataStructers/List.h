#pragma once
#include "Vertex.h"

class List{
  public:
	//////////////////CONSTRUCTORS//////////////////
	List() : _size(0), _head(nullptr), _tail(nullptr){};
	List(List &L);
	//////////////////DESTRUCTOR//////////////////
	~List();
	//////////////////METHODS//////////////////
	bool find(int num);
	void insertToHead(Vertex *v);
	void insertToTail(Vertex *v);
	void deleteNode(int num);
	void printAdjList(int u);
	void emptyList();
	void copyList(List &L);
	bool isEmpty(){ return this->_size == 0; };
	friend ostream &operator<<(ostream &os, List &L){
		
		Vertex *curr = L._head;
		
		while(curr != nullptr){
			os << curr->data() << ", ";
			
			curr = curr->getNext();
		}
		cout << endl;
		
		return os;
	}
	Vertex *getHead(){ return this->_head; };
  
  private:
	int _size;
	Vertex *_head, *_tail;
};