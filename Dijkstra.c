/*
    Algorithm for Dijkstra(G, W, S){
        Initialize_single_source(G,S)
        S = null(empty)

        (MinHeap)Q =  G.V
        while Q != null{
            U = extract_Min(Q);
            S = S union {u}
        
            for each vertex v belonging to G.ajacent[u]{
                Relax (u, v, w)
            }
        }
    }
*/