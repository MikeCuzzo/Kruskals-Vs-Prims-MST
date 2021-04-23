//
// Created by mcuzzo on 4/23/21.
//

#ifndef S21_PA04_MIKECUZZO_GRANTAYERS_UNIONFIND_H
#define S21_PA04_MIKECUZZO_GRANTAYERS_UNIONFIND_H

#include <boost/graph/adjacency_list.hpp>

using namespace std;
using namespace boost;


class UnionFind {
public:
    UnionFind(adjacency_list<listS, vecS, undirectedS>);
    int find();
    void getUnion();
private:
    typedef adjacency_list<listS, vecS, undirectedS> Graph;
    Graph g;
};


#endif //S21_PA04_MIKECUZZO_GRANTAYERS_UNIONFIND_H
