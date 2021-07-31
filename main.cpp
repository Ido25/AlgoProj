#include <iostream>
#include "DataStructers\Graph.h"
#include "Algorhitms.h"
#include <chrono>
#include <iomanip>

//TODO: add check if Q/List/Graph is empty where needed

void killMe(){
	
	cout << "invalid input";
	exit(1);
}
int main(){
	
	set_terminate(killMe);
	
	Graph G, res;
	
	G.readGraph();
	
	auto start = chrono::high_resolution_clock::now();
// unsync the I/O of C and C++.
	ios_base::sync_with_stdio(false);
	algos::buildShortestPathsGraph(G, res);// Here you put the name of the function you wish to measure
	auto end = chrono::high_resolution_clock::now();
// Calculating total time taken by the program.
	double time_taken =
			chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	ofstream myfile("Measure.txt"); // The name of the file
	myfile << "Time taken by function <name-of-fun> is : " << fixed
		   << time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();
	
	res.printBFSGraph(res.getS());
	return 0;
}
