//
// Created by mcuzzo on 4/15/21.
//

#ifndef S21_PA04_MIKECUZZO_GRANTAYERS_PRIMS_H
#define S21_PA04_MIKECUZZO_GRANTAYERS_PRIMS_H

#include <boost/graph/adjacency_list.hpp>
#include "iostream"
#include "vector"

using namespace std;
using namespace boost;

class Prims {
public:
    Prims(adjacency_list<listS, vecS, undirectedS>);
    void primMST();
    int minKey(vector<int>, vector<bool>);
    void printMST(vector<int>);
private:
    typedef adjacency_list<listS, vecS, undirectedS> Graph;
    typedef Graph::edge_descriptor Edge;
    Graph g;
    int V;
};


#endif //S21_PA04_MIKECUZZO_GRANTAYERS_PRIMS_H
