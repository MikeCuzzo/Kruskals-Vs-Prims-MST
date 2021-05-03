//
// Created by mcuzzo on 4/15/21.
//

#include "Kruskals.h"

Kruskals::Kruskals(adjacency_list<listS, vecS,undirectedS,no_property,property<edge_weight_t, int>> gr) {
    g = gr;
    num_edges = 0;
    total_weight = kruskalMST();
}

int Kruskals::kruskalMST() {
    // Initialize result
    int mst_wt = 0;

    //Initialize UnionFind class
    UnionFind uf = UnionFind(num_vertices(g));


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
            // so print it and add to the number of edges
            // cout << u << " - " << v << endl;
            num_edges += 1;

            // Update MST weight
            mst_wt += get(edge_weight_t(),g,edge(u,v,g).first);

            // Merge two sets
            uf.Union(set_u, set_v);
        }
    }

    return mst_wt;
}
int Kruskals::get_total_weight(){
    return total_weight;
}
int Kruskals::get_total_edges(){
    return num_edges;
}