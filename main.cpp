#include <iostream>
#include "DataStructers\Graph.h"
#include "Algorhitms.h"

int main(){
	
	try{
		Graph G;
		
		G.readGraph();
		
		Graph H;
		H = algos::buildShortestPathsGraph(G);
		
		H.printGraph();
	} catch(string msg){
		cout << msg << endl;
	}
	
	return 0;
}
