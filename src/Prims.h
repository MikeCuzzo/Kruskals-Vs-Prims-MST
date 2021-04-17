//
// Created by mcuzzo on 4/15/21.
//

#ifndef S21_PA04_MIKECUZZO_GRANTAYERS_PRIMS_H
#define S21_PA04_MIKECUZZO_GRANTAYERS_PRIMS_H

#include <boost/graph/adjacency_list.hpp>

using namespace std;
using namespace boost;

class Prims {
public:
    Prims(adjacency_list<listS, vecS, undirectedS>);
private:
    typedef adjacency_list<listS, vecS, undirectedS> Graph;
    Graph g;
};


#endif //S21_PA04_MIKECUZZO_GRANTAYERS_PRIMS_H
