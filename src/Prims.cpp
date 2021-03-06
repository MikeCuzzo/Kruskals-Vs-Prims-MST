//
// Created by mcuzzo on 4/15/21.
//

#include "Prims.h"

// implementation referenced from geeksforgeeks


Prims::Prims(adjacency_list<listS, vecS,undirectedS,no_property,property<edge_weight_t, int>> gr) {
    g = gr;
    V = num_vertices(g);

    parent.reserve(V);
    key.reserve(V);
    mstSet.reserve(V);
    primMST();
}

void Prims::primMST() {
    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Always include first 1st vertex in MST.
    // Make key 0 so that this vertex is picked as first vertex.
    key[0] = 0;
    parent[0] = -1; // First node is always root of MST


    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++){
        // Pick the minimum key vertex from the
        // set of vertices not yet included in MST
        int u = minKey();

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of
        // the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not
        // yet included in MST
        graph_traits<Graph>::edge_iterator ei, ei_end;
        for (int v = 0; v < V-1; v++) {
            // graph[u][v] is non zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (edge(u,v,g).second && mstSet[v] == false && edge(u,v,g).second < key[v]) {
                parent[v] = u, key[v] = edge(u, v, g).second;
            }
        }
    }
}

// A utility function to find the vertex with
// minimum key value, from the set of vertices
// not yet included in MST
int Prims::minKey() {
    // Initialize min value
    int min = INT_MAX;
    int min_index = 0;

    for (int v = 0; v < V; v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

int Prims::get_total_weight(){
    int total_weight = 0;
    for (int i = 1; i < V-2; i++)
        total_weight += get(edge_weight_t(), g, edge(i,parent[i],g).first);

    return total_weight;
}

int Prims::get_total_edges(){
    return num_edges(g);
}