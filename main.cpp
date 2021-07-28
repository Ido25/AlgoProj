#include <iostream>
#include "DataStructers\Graph.h"
#include "Algorhitms.h"

//TODO: add check if Q/List/Graph is empty where needed
int main(){
	
	try{
		Graph G, res;
		
		G.readGraph();
		G.printGraph();
		
		algos::buildShortestPathsGraph(G, res);
		
		res.printGraph();
	} catch(string msg){
		cout << msg << endl;
	}
	
	return 0;
}
