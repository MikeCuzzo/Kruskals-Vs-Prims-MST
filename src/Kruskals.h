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
    Kruskals(adjacency_list<listS, vecS, undirectedS>);
    int kruskalMST();
    void printMST(vector<int>);
private:
    typedef adjacency_list<listS, vecS, undirectedS> Graph;
    Graph g;
    // first int is parent, second is rank
    vector<boost::tuple <int,int>> DisjointSets;
    int V;
};


#endif //S21_PA04_MIKECUZZO_GRANTAYERS_KRUSKALS_H
