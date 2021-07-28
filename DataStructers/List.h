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
	void insertToHead(int v);
	void insertToTail(int v);
	Vertex *deleteNode(int num);
	void printAdjList(int u);
	void emptyList();
	void copyList(List &L);
	bool isEmpty(){ return this->_size == 0; };
	Vertex *getHead(){ return this->_head; };
	int getSize(){ return this->_size; };
	friend ostream &operator<<(ostream &os, List &L){
		
		Vertex *curr = L._head;
		
		while(curr != nullptr){
			os << curr->data() << ", ";
			
			curr = curr->getNext();
		}
		cout << endl;
		
		return os;
	}
  
  private:
	int _size;
	Vertex *_head, *_tail;
};