//
// Created by mcuzzo on 4/15/21.
//

#ifndef S21_PA04_MIKECUZZO_GRANTAYERS_PRIMS_H
#define S21_PA04_MIKECUZZO_GRANTAYERS_PRIMS_H

#include <boost/graph/adjacency_list.hpp>
#include "iostream"
#include "vector"
#include "boost/graph/graph_utility.hpp"

using namespace std;
using namespace boost;

class Prims {
public:
    Prims(adjacency_list<listS, vecS,undirectedS,no_property,property<edge_weight_t, int>>);
    void primMST();
    int minKey();
    void printMST();
    int get_total_weight();
    int get_total_edges();
private:
    typedef property<boost::edge_weight_t, int> EdgeWeightProperty;
    typedef adjacency_list<listS, vecS,undirectedS,no_property,EdgeWeightProperty> Graph;
    typedef Graph::edge_descriptor Edge;
    Graph g;
    int V;
    // Vector to store constructed MST
    vector<int> parent;
    // Key values used to pick minimum weight edge in cut
    vector<int> key;
    // To represent set of vertices included in MST
    vector<bool> mstSet;
    int total_edges;
    int total_weight;
};


#endif //S21_PA04_MIKECUZZO_GRANTAYERS_PRIMS_H
