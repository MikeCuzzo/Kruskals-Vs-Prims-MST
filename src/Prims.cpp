//
// Created by mcuzzo on 4/15/21.
//

#include "Prims.h"

Prims::Prims(adjacency_list<listS, vecS, undirectedS> gr) {
    g = gr;
    V = num_vertices(g);
    primMST();
}

void Prims::primMST() {
    // Array to store constructed MST
    vector<int> parent;

    // Key values used to pick minimum weight edge in cut
    vector<int> key;

    // To represent set of vertices included in MST
    vector<bool> mstSet;

    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    // Always include first 1st vertex in MST.
    // Make key 0 so that this vertex is picked as first vertex.
    key[0] = 0;
    parent[0] = -1; // First node is always root of MST


    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++)
    {
        // Pick the minimum key vertex from the
        // set of vertices not yet included in MST
        int u = minKey(key, mstSet);

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of
        // the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not
        // yet included in MST
        graph_traits<Graph>::edge_iterator ei, ei_end;
        for (int v = 0; v < V; v++) {
            // graph[u][v] is non zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (edge(u,v,g).second && mstSet[v] == false && edge(u,v,g).second < key[v])
                parent[v] = u, key[v] = edge(u,v,g).second;
        }
    }

    // print the constructed MST
    printMST(parent);
}

// A utility function to find the vertex with
// minimum key value, from the set of vertices
// not yet included in MST
int Prims::minKey(vector<int> key, vector<bool> mstSet) {
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

// A utility function to print the
// constructed MST stored in parent[]
void Prims::printMST(vector<int> parent) {
    cout <<"Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout <<parent[i]<<" - "<<i<<" \t"<< edge(i,parent[i],g).second <<" \n";
}
