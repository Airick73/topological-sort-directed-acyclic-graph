#ifndef __DIGRAPH_H
#define __DIGRAPH_H

#include <unordered_map>
#include <map>
#include <unordered_set>
#include <stdexcept>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class DigraphMatrix
{
public:
  DigraphMatrix(const string& filename);

  vector<int> topologicalSort() const;
  void addEdge(const int&, const int&);

  void DFS(const int& v);
  void printDFS(const int& start);

  int** createMatrix(int, int); 
  void displayMatrix();

private:
  int numVertices;
  enum mark_t { UNDISCOVERED, DISCOVERED, EXPLORED };
  map<int, mark_t> marks;
  int numEdges;
  int** adjMatrix;
  string file; //string to hold filename
  bool aCycle = false;
  vector<int> sortedList;
};
#endif