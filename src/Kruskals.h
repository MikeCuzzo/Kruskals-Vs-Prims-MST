//
// Created by mcuzzo on 4/15/21.
//

#ifndef S21_PA04_MIKECUZZO_GRANTAYERS_KRUSKALS_H
#define S21_PA04_MIKECUZZO_GRANTAYERS_KRUSKALS_H

#include <boost/graph/adjacency_list.hpp>
#include "UnionFind.h"
#include "iostream"
#include "vector"

using namespace std;
using namespace boost;


class Kruskals {
public:
    Kruskals(adjacency_list<listS, vecS,undirectedS,no_property,property<edge_weight_t, int>>);
    int kruskalMST();
    int get_total_weight();
    int get_total_edges();
private:
    typedef property<edge_weight_t, int> EdgeWeightProperty;
    typedef adjacency_list<listS, vecS,undirectedS,no_property,EdgeWeightProperty> Graph;
    Graph g;
    // first int is parent, second is rank
    vector<boost::tuple <int,int>> DisjointSets;
    int V;
    int num_edges;
    int total_weight;
};


#endif //S21_PA04_MIKECUZZO_GRANTAYERS_KRUSKALS_H
