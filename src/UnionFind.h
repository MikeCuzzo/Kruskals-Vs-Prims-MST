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
    UnionFind(int);
    int find(int);
    void Union(int,int);

private:
    vector<int> parent;
    vector<int> rnk;
};


#endif //S21_PA04_MIKECUZZO_GRANTAYERS_UNIONFIND_H
