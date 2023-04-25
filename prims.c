/*
    Algorithm for prims algorithm

    MST is computed and is stored in T.
    let (k,l) be the edge of min cost in E

    T[1,1] = k
    T[1,2] = l

    for (i = 1 to n){
        if (cost[i,l] < cost[i,k]){
            near[i] = l
        }
        else{
            near[i] = k
        }
    }

    near[k] = near[l] = 0

    for(i=2 to n-1)
    {
        Let j be an index such that near[j] != 0 and cost[j, near[j]] is min
        t[i,1] = j
        t[i,2] = near[j]

        mincost = mincost + cost[j, near[j]]
        near[j] = 0

        for(k=1 to n){
            if near[k] != 0 and cost[k,near[k]]> cost[i,j]{
                near[k] = j
            }
        }
    } 
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100

typedef struct {
    int node1, node2, weight;
} Edge;

typedef struct {
    int num_nodes;
    int num_edges;
    int adj_mat[MAX_NODES][MAX_NODES];
} Graph;

void primMST(Graph *graph) {
    int i, j, k, min, min_cost = 0;
    int near[MAX_NODES];
    Edge T[MAX_NODES - 1];

    // Initialization
    for (i = 1; i <= graph->num_nodes; i++) {
        near[i] = 1;
    }

    // Find MST
    for (i = 0; i < graph->num_nodes; i++) {
        // Find edge of min cost
        min = INT_MAX;
        for (j = 2; j <= graph->num_nodes; j++) {
            if (near[j] != 0) {
                for (k = 1; k < j; k++) {
                    if (near[k] == 0 && graph->adj_mat[j][k] < min) {
                        min = graph->adj_mat[j][k];
                        T[i].node1 = j;
                        T[i].node2 = k;
                        T[i].weight = min;
                    }
                }
            }
        }

        // Add to MST
        near[T[i].node1] = 0;
        near[T[i].node2] = 0;
        min_cost += T[i].weight;

        // Update near array
        for (j = 1; j <= graph->num_nodes; j++) {
            if (near[j] != 0 && graph->adj_mat[j][T[i].node1] < graph->adj_mat[j][T[i].node2]) {
                near[j] = T[i].node1;
            }
            else if (near[j] != 0 && graph->adj_mat[j][T[i].node2] < graph->adj_mat[j][T[i].node1]) {
                near[j] = T[i].node2;
            }
        }
    }

    // Print MST
    printf("Edges in MST:\n");
    for (i = 1; i < graph->num_nodes; i++) {
        printf("(%d, %d) with weight %d\n", T[i].node1, T[i].node2, T[i].weight);
    }
    printf("Total cost of MST: %d\n", min_cost);
}

int main() {
    int i, j;
    Graph graph;

    printf("Enter number of nodes: ");
    scanf("%d", &graph.num_nodes);

    printf("Enter adjacency matrix:\n");
    for (i = 1; i <= graph.num_nodes; i++) {
        for (j = 0; j <= graph.num_nodes; j++) {
            scanf("%d", &graph.adj_mat[i][j]);
        }
    }

    primMST(&graph);

    return 0;
}
