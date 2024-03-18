
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Graph.h"

// depth-first search to check for cycles using the lec code
bool dfsCycleCheck(Graph g, int v, int primary_graph, bool visited[])
{

    visited[v] = true;

    for (int w = 0; w < numOfVertices(g); w++)
    {
        if (adjacent(g, v, w))
        {
            if (!visited[w])
            {
                if (dfsCycleCheck(g, w, v, visited))
                {
                    // Cycle found in the subtree: Cycle detected within the current vertex's subtree.
                    return true;
                }
            }
            else if (w != primary_graph)
            {
                // Cycle found (back edge): Cycle detected by encountering an edge to a previously visited ancestor.
                return true;
            }
        }
    }
    // no cycle
    return false;
}

// check if the graph has a cycle using depth-first search
bool hasCycle(Graph g)
{

    bool *visited = malloc(numOfVertices(g) * sizeof(bool));
    if (visited == NULL)
    {
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < numOfVertices(g); i++)
    {
        visited[i] = false;
    }

    // do dfs from each vertex
    for (int v = 0; v < numOfVertices(g); v++)
    {
        if (!visited[v])
        {
            if (dfsCycleCheck(g, v, -1, visited))
            { // Start DFS from vertex v
                free(visited);
                return true; // Cycle found
            }
        }
    }

    free(visited);
    return false; // No cycle
}

int main()
{
    int num_vertices;

    printf("Enter the number of vertices: ");
    if (scanf("%d", &num_vertices) != 1 || num_vertices <= 0)
    {
        return 1;
    }

    // Create a new graph
    Graph g = newGraph(num_vertices);

    // Input edges from the user
    int edge_from, edge_to;
    while (true)
    {
        printf("Enter an edge (from): ");
        int edge_from_value = scanf("%d", &edge_from);
        if (edge_from_value != 1)
        {
            printf("Done.\n");
            break;
        }
        printf("Enter an edge (to): ");
        int edge_to_value = scanf("%d", &edge_to);
        if (edge_to_value != 1)
        {
            printf("Done.\n");
            break;
        }

        // if (edge_from < 0 OR edge_from >= graph_vertices_number OR edge_to < 0 OR edge_to >= graph_vertices_number)
        if (edge_from < 0 || edge_from >= num_vertices || edge_to < 0 || edge_to >= num_vertices)
        {
            printf("Done.\n");
            freeGraph(g);
            return 1;
        }
        Edge e = {edge_from, edge_to};
        insertEdge(g, e);
    }

    // check and print
    if (hasCycle(g))
    {
        printf("The graph has a cycle.\n");
    }
    else
    {
        printf("The graph is acyclic.\n");
    }

    freeGraph(g);

    return 0;
}

// gcc -Wall -Werror -std=c11 -o cycleCheck cycleCheck.c Graph.c
//  ./cycleCheck   //9024 dryrun cycleCheck