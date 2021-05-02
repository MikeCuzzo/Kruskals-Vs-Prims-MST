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
private:
    typedef property<boost::edge_weight_t, int> EdgeWeightProperty;
    typedef adjacency_list<listS, vecS,undirectedS,no_property,EdgeWeightProperty> Graph;
    typedef Graph::edge_descriptor Edge;
    Graph g;
    int V;
    // Vector to store constructed MST
    vector<int> parent;
    // Key values used to pick minimum weight edge in cut
    // second value is to represent set of vertices included in MST
    vector<boost::tuple<int,bool>> key;
};


#endif //S21_PA04_MIKECUZZO_GRANTAYERS_PRIMS_H
