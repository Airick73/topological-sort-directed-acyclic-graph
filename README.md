# topological_sort_directed_acyclic_graph
This program takes in a text file in a specific format represeting a directed graph and returns the the verticies topologically sorted or throws an expection if a cycle was detected. 

Input file:
The input graph is described in edge list format. The first line of the file has the number of vertices
and edges of the graph, separated by a space (n and m, respectively).
The following m lines have two nonnegative integers each. These integers, u and v, will be in
the range 0 to n − 1, and they represent the endpoints of an edge in the graph. Specifically, they
represent an edge from u to v.

To run this program:
g++ digraph.cpp digraph.h driver.cpp

Example output:
0 1 0 0 0 0 0 0 
0 0 0 0 1 0 0 1 
0 0 0 0 0 0 0 0 
0 0 0 0 0 0 1 1 
0 0 0 0 0 0 0 0 
0 0 0 0 1 0 0 0
1 0 1 0 0 0 0 0 
0 0 0 0 0 0 0 0

checking marks map
{0: 0}
{1: 0}
{2: 0}
{3: 0}
{4: 0}
{5: 0}
{6: 0}
{7: 0}

0,
0 discoverd
1 undiscovered
1,
1 discoverd
4 undiscovered
4,
4 discoverd
4 explored
7 undiscovered
7,
7 discoverd
7 explored
1 explored
0 explored

2, 
2 discoverd
2 explored
3,
3 discoverd
6 undiscovered
6,
6 discoverd
6 explored
3 explored
5,
5 discoverd
5 explored

5 3 6 2 0 1 7 4
