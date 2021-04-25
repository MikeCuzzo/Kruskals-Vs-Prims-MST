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
//    // Initialize result
//    int mst_wt = 0;
//
//    //Initialize UnionFind class
//    UnionFind u = UnionFind(g);
//
//    // Sort edges in increasing order on basis of cost
//    sort(edges.begin(), edges.end());
//
//    // Create disjoint sets
//    getDisjointSets();
//
//    // Iterate through all sorted edges
//    vector<pair<int, iPair> >::iterator it;
//    for (it=edges.begin(); it!=edges.end(); it++)
//    {
//        int u = it->second.first;
//        int v = it->second.second;
//
//        int set_u = u.find(u);
//        int set_v = u.find(v);
//
//        // Check if the selected edge is creating
//        // a cycle or not (Cycle is created if u
//        // and v belong to same set)
//        if (set_u != set_v)
//        {
//            // Current edge will be in the MST
//            // so print it
//            cout << u << " - " << v << endl;
//
//            // Update MST weight
//            mst_wt += it->first;
//
//            // Merge two sets
//            u.Union(set_u, set_v);
//        }
//    }
//
//    return mst_wt;
}

void Kruskals::getDisjointSets() {
    // Initially, all vertices are in
    // different sets and have rank 0.
    for (int i = 0; i <= V; i++)
    {
        DisjointSets[i].get<1>() = 0;

        //every element is parent of itself
        DisjointSets[i].get<0>() = i;
    }
}