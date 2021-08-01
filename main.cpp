/*
 * submitter: Ido Medina, ID: 316082106
 *
 * This program gets a graph and 2 vertexes, t and s, and is prints the graph of the shortest paths from s to t.
 * It works by the algorithm that we got in the task description.
 * */
#include "configs.h"
#include "DataStructers\Graph.h"
#include "Algorhitms.h"

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
	myfile << "Time taken by function buildShortestPathsGraph is : " << fixed
		   << time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();
	
	res.printGraph();
	return 0;
}
