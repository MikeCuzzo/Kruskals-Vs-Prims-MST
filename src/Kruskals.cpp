//
// Created by mcuzzo on 4/15/21.
//

#include "Kruskals.h"

Kruskals::Kruskals(adjacency_list<listS, vecS, undirectedS> gr) {
    g = gr;
    V = num_vertices(g);
    kruskalMST();
}

int Kruskals::kruskalMST() {
    // Initialize result
    int mst_wt = 0;

    //Initialize UnionFind class
    UnionFind uf = UnionFind(num_vertices(g));

//    // Sort edges in increasing order on basis of cost
//    sort(edges.begin(), edges.end());


    // Iterate through all  edges
    graph_traits<Graph>::edge_iterator ei, ei_end;
    typedef property_map<Graph, vertex_index_t>::type IndexMap;
    IndexMap index = get(vertex_index, g);
    for (tie(ei, ei_end) = edges(g); ei != ei_end; ++ei)
    {
        int u = index[source(*ei, g)];
        int v = index[target(*ei, g)];

        int set_u = uf.find(u);
        int set_v = uf.find(v);

        // Check if the selected edge is creating
        // a cycle or not (Cycle is created if u
        // and v belong to same set)
        if (set_u != set_v)
        {
            // Current edge will be in the MST
            // so print it
            cout << u << " - " << v << endl;

            // Update MST weight
            mst_wt += index[source(*ei, g)];

            // Merge two sets
            uf.Union(set_u, set_v);
        }
    }

    return mst_wt;
}

// A utility function to print the
// constructed MST stored in parent[]
void Kruskals::printMST(vector<int> parent) {
    cout <<"Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout <<parent[i]<<" - "<<i<<" \t"<< edge(i,parent[i],g).second <<" \n";
}