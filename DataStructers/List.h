/*
 * This is the List class.
 * It's implemented by a 2-way list of vertexes.
 * */
#pragma once
#include "Vertex.h"

class List{
  public:
	//////////////////CONSTRUCTORS//////////////////
	List() : _size(0), _head(nullptr), _tail(nullptr){};//default constructor
	List(List &L);//copy constructor
	//////////////////DESTRUCTOR//////////////////
	~List();
	//////////////////METHODS//////////////////
	bool find(int num);//this func receives a number and returns whether there is a node with this number or not
	void insertToHead(int v);//this func gets a number and inserts a new node with the number to the list's head
	void insertToTail(int v);//this func gets a number and inserts a new node with the number to the list's tail
	Vertex *deleteNode(int num);//this func gets a number and deletes it's node from the list
	void
	printAdjList(int u);//this func gets a vertex number and prints the lists as edges from the u vertex to each node
	void emptyList();//this func empties the list
	void copyList(List &L);//this func makes a deep copy of the list L
	bool isEmpty(){ return this->_size == 0; };//this func checks whether the list is empty or not
	Vertex *getHead(){ return this->_head; };//this func returns a pointer to the list's head
	int getSize(){ return this->_size; };//this func returns the list's size
	friend ostream &operator<<(ostream &os, List &L){//printing operator
		
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