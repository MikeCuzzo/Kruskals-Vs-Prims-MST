//
// Created by mcuzzo on 4/23/21.
//

#include "UnionFind.h"

// implementation referenced from geeksforgeeks

UnionFind::UnionFind(adjacency_list<listS, vecS, undirectedS> gr) {
    g = gr;
}

// The main function to check whether a given graph contains
// cycle or not
bool UnionFind::isCycle()
{
    int V = num_vertices(g);
    int E = num_edges(g);

    for (int v = 0; v < V; ++v) {
        subsets[v].get<0>() = v;
        subsets[v].get<1>() = 0;
    }

    // Iterate through all edges of graph, find sets of both
    // vertices of every edge, if sets are same, then there
    // is cycle in graph.
    for (int e = 0; e < E; ++e) {
//        int x = find(subsets, g.edge[e].src);
//        int y = find(subsets, g->edge[e].dest);


        if (x == y)
            return true;

        Union(subsets, x, y);
    }
    return false;
}

// A utility function to find set of an element i
// (uses path compression technique)
int find(vector<boost::tuple<int,int>> subsets, int i)
{
    // find root and make root as parent of i (path
    // compression)
    if (subsets[i].get<0>() != i)
        subsets[i].get<0>()
                = find(subsets, subsets[i].get<0>());

    return subsets[i].get<0>();
}

// A function that does union of two sets of x and y
// (uses union by rank)
void Union(vector<boost::tuple<int,int>> subsets, int xroot, int yroot)
{

    // Attach smaller rank tree under root of high rank tree
    // (Union by Rank)
    if (subsets[xroot].get<1>() < subsets[yroot].get<1>())
        subsets[xroot].get<0>() = yroot;
    else if (subsets[xroot].get<1>() > subsets[yroot].get<1>())
        subsets[yroot].get<0>() = xroot;

        // If ranks are same, then make one as root and
        // increment its rank by one
    else {
        subsets[yroot].get<0>() = xroot;
        subsets[xroot].get<1>()++;
    }
}