//
// Created by mcuzzo on 4/15/21.
//

#ifndef S21_PA04_MIKECUZZO_GRANTAYERS_GRAPHENGINE_H
#define S21_PA04_MIKECUZZO_GRANTAYERS_GRAPHENGINE_H

#include "iostream"
#include "fstream"
#include <boost/graph/adjacency_list.hpp>
#include "Kruskals.h"
#include "Prims.h"
#include "chrono"
#include "boost/graph/graph_utility.hpp"

using namespace std;
using namespace boost;
using namespace chrono;

class GraphEngine {
public:
    GraphEngine();
    void generateGraph();
    void algTiming(adjacency_list<listS, vecS, undirectedS>);
private:
    typedef adjacency_list<listS, vecS, undirectedS> Graph;
};


#endif //S21_PA04_MIKECUZZO_GRANTAYERS_GRAPHENGINE_H
