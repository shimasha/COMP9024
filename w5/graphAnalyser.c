//
//  graphAnalyser.c
//
//
//  Created by Alexis  on 18/3/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "Graph.h"

// Declarations
int *graph_degree_find(Graph g);
void graph_3cliques_find(Graph g);
double graph_density_find(Graph g);

// graph_degree_find function

int *graph_degree_find(Graph g)
{
    int graph_vertices_number = num_Vertices(g);
    int *degrees = (int *)malloc(graph_vertices_number * sizeof(int));
    if (degrees == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int v = 0; v < graph_vertices_number; v++)
    {
        degrees[v] = 0;
        for (int w = 0; w < graph_vertices_number; w++)
        {
            if (v != w && adjacent(g, v, w))
            {
                degrees[v]++;
            }
        }
    }

    return degrees;
}

// Function edge_to compute and display all 3-cliques
void graph_3cliques_find(Graph g)
{
    int graph_vertices_number = num_Vertices(g);

    for (int v = 0; v < graph_vertices_number; v++)
    {
        for (int w = v + 1; w < graph_vertices_number; w++)
        {
            if (adjacent(g, v, w))
            {
                for (int x = w + 1; x < graph_vertices_number; x++)
                {
                    if (adjacent(g, v, x) && adjacent(g, w, x))
                    {
                        printf("%d-%d-%d\n", v, w, x);
                    }
                }
            }
        }
    }
}

// Function edge_to compute the density of the graph
double graph_density_find(Graph g)
{
    int graph_vertices_number = num_Vertices(g);
    int numEdges = 0;

    // Count the number of edges
    for (int i = 0; i < graph_vertices_number; i++)
    {
        for (int j = i + 1; j < graph_vertices_number; j++)
        {
            if (adjacent(g, i, j))
            {
                numEdges++;
            }
        }
    }

    // Check if the graph has no vertices or only one vertex
    if (graph_vertices_number <= 1)
        return 0.0;

    // Compute density
    double density = (2.0 * numEdges) / (graph_vertices_number * graph_vertices_number);
    return density;
}

// Main function

int main()
{
    int graph_vertices_number;

    printf("Enter the number of vertices: ");
    if (scanf("%d", &graph_vertices_number) != 1 || graph_vertices_number <= 0)
    {
        return 1;
    }

    // Create a new graph
    Graph g = newGraph(graph_vertices_number);

    // user input edges
    int edge_from, edge_to;
    while (true)
    {
        printf("Enter an edge (from): ");
        int edge_from_value = scanf("%d", &edge_from);
        if (edge_from_value != 1)
        {
            printf("Done\n");
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
        if (edge_from < 0 || edge_from >= graph_vertices_number || edge_to < 0 || edge_to >= graph_vertices_number)
        {
            printf("Done.\n");
            freeGraph(g);
            return 1;
        }
        Edge e = {edge_from, edge_to};
        insertEdge(g, e);
    }

    // Compute and display the degree of each vertex
    printf("Degree of each vertex:\n");
    int *degrees = graph_degree_find(g);
    for (int i = 0; i < graph_vertices_number; i++)
    {
        printf("Degree of node %d: %d\n", i, degrees[i]);
    }
    free(degrees);

    // Compute and display all 3-cliques
    printf("3-cliques:\n");
    graph_3cliques_find(g);

    // Compute and display the density of the graph
    double density = graph_density_find(g);
    printf("Density: %.3f\n", density);

    // Free memory
    freeGraph(g);

    return 0;
}

// gcc -Wall -Werror -std=c11 -o graphAnalyser graphAnalyser.c Graph.c
//  ./graphAnalyser