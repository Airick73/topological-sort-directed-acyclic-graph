#include "digraph.h"
#include <unordered_map>
#include <unordered_set>
#include <stdexcept>
#include <string>
#include <vector>
#include <iostream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <stack>
#include<map>
using namespace std;

//constructor for diagraphMatrix class taking in a filename
DigraphMatrix::DigraphMatrix(const string& filename){
    this->file = filename; //private data member: string file 
    ifstream in(this->file); 
    if (!in.is_open()){ //trying to open file else throwing error
        cout << "Couldn't open graph.txt\n";
    }

    int nV, nE; //# of verticies & edges
    in >> nV >> nE; //first two ints in file (seperated by white space)
    this->numVertices = nV; //private data memeber: int numVertices
    this->numEdges = nE;  //private data memeber: int numEdges
    in.ignore(); //Ignore \n

    //matrix size will be numVertices by numVertices
    this->adjMatrix = new int*[numVertices]; //private data memeber: int** adjMatrix
    for(int i = 0; i < numVertices; ++i) //setting size of 2d adjMatrix
        adjMatrix[i] = new int[numVertices];

    //intialize graph to contain all 0s
    int pos = 0;
    int sizeVar = numVertices * numVertices;
    int intializerArr[sizeVar] = {0}; //sizeVar declared at run time
    for(int i = 0; i < nV; i++){
        for(int j = 0; j < nV; j++){
            adjMatrix[i][j] = intializerArr[pos++];
        }
    }

    //Read in n vertices and intilize matrix 
    int u, v;
    for (int i = 0; i < numEdges; i++){
        in >> u >> v; 
        addEdge(u, v); //just marking position u,v in adjMatrix = 1
        in.ignore();  //Ignore \n
    }
    
    displayMatrix();
    cout << endl;

    printDFS(0);

    for (auto const &pair: this->marks) {
        if(pair.second == UNDISCOVERED)
            DFS(pair.first);
    }
    
    //reversing list for final output
    reverse(this->sortedList.begin(), this->sortedList.end()); 

    cout << endl;

}

void DigraphMatrix::addEdge(const int& u, const int& v){
    this->adjMatrix[u][v] = 1; 
}

//Depth first search algorithm 
void DigraphMatrix::DFS(const int& v){
  cout << v << ", "; //print first verticie
  this->marks[v] = DISCOVERED; //private data memeber: map<int, mark_t> marks;
  cout << endl << v << " discoverd" << endl;

  //Recurse on undiscovered neighbors
  for (int i = 0; i < this->numVertices; i++)
    if(this->adjMatrix[v][i] == 1){ //go down row of adjMatrix to find adj neighbors
        if (this->marks[i] == UNDISCOVERED){
            cout << i << " undiscovered" << endl;
            DFS(i);
        }
        else if(this->marks[i] == DISCOVERED)
            this->aCycle = true;
    }

  this->marks[v] = EXPLORED;
  this->sortedList.push_back(v);
  cout << v << " explored" << endl;
}

vector<int> DigraphMatrix::topologicalSort() const{
    if(this->aCycle) throw exception();
    return this->sortedList; 
}

////////////////////////////////////////////////////////
/////////////////Utility functions//////////////////////
////////////////////////////////////////////////////////

//function to print the depth first search
void DigraphMatrix::printDFS(const int& start){ 
  //Mark all vertices undiscovered
  for(int i = 0; i < this->numVertices; i++)
    this->marks.insert(make_pair(i, UNDISCOVERED));

  cout << "checking marks map " << endl; 
  for (auto const &pair: this->marks) {
        cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
  cout << endl;

  DFS(start);
  cout << endl;
}

//function to display matrix using a for loop
void DigraphMatrix::displayMatrix(){ 
   int i, j;
   for(i = 0; i < this->numVertices; i++) {
      for(j = 0; j < this->numVertices; j++) {
         cout << this->adjMatrix[i][j] << " ";
      }
      cout << endl;
   }
}