//
// Created by mcuzzo on 4/23/21.
//

#include "UnionFind.h"

// implementation referenced from geeksforgeeks

UnionFind::UnionFind(int n) {
    // Initially, all vertices are in
    // different sets and have rank 0.
    for (int i = 0; i <= n; i++)
    {
        rnk[i] = 0;

        //every element is parent of itself
        parent[i] = i;
    }
}

// Find the parent of a node 'u'
// Path Compression
int UnionFind::find(int u) {
    /* Make the parent of the nodes in the path
       from u--> parent[u] point to parent[u] */
    if (u != parent[u])
        parent[u] = find(parent[u]);
    return parent[u];
}

// A function that does union of two sets of x and y
// (uses union by rank)
void UnionFind::Union(int x, int y) {
    x = find(x), y = find(y);

    /* Make tree with smaller height
       a subtree of the other tree  */
    if (rnk[x] > rnk[y])
        parent[y] = x;
    else // If rnk[x] <= rnk[y]
        parent[x] = y;

    if (rnk[x] == rnk[y])
        rnk[y]++;
}