//
//  Graph.h
//
//
//  Created by Alexis  on 18/3/2024.
//
// Graph ADT interface ... COMP9024 24T1
#include <stdbool.h>

typedef struct GraphRep *Graph;

// vertices are ints
typedef int Vertex;

// edges are pairs of vertices (end-points)
typedef struct Edge
{
   Vertex v;
   Vertex w;
} Edge;

Graph newGraph(int);
int num_Vertices(Graph);
void insertEdge(Graph, Edge);
void removeEdge(Graph, Edge);
bool adjacent(Graph, Vertex, Vertex);
void showGraph(Graph);
void freeGraph(Graph);
