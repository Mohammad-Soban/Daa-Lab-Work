#include <stdio.h>
#include <stdlib.h>

/*
Krusals{
    Algorithm for kruskal's algorithm
    A is the MST and is initially null;

    for each vertex v belonging to G.V{
        make_set(v)
    }

    for eacn edge (u,v) belonging to G.E order in ascending order of weight (u,v)
    {
        if Find_set(u) != Find_set(v){
            A = A union {u,v}
            UNION (u,v)
            return A
        } 
    }    
}

*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_EDGES 10000

typedef struct {
    int u, v, w;
} Edge;

int parent[MAX_VERTICES];

int findSet(int x) {
    if (parent[x] == x) {
        return x;
    } else {
        parent[x] = findSet(parent[x]);
        return parent[x];
    }
}

void unionSets(int x, int y) {
    int px = findSet(x), py = findSet(y);
    parent[px] = py;
}

int cmpEdges(const void *a, const void *b) {
    Edge *ea = (Edge *) a, *eb = (Edge *) b;
    return ea->w - eb->w;
}

int main() {
    int n, m;
    Edge edges[MAX_EDGES], mst[MAX_VERTICES];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }
    qsort(edges, m, sizeof(Edge), cmpEdges);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    int mstSize = 0;
    for (int i = 0; i < m; i++) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if (findSet(u) != findSet(v)) {
            mst[mstSize++] = edges[i];
            unionSets(u, v);
        }
    }
    printf("Minimum spanning tree:\n");
    for (int i = 0; i < mstSize; i++) {
        printf("%d %d %d\n", mst[i].u, mst[i].v, mst[i].w);
    }
    return 0;
}
