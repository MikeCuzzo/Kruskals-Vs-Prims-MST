//
// Created by mcuzzo on 4/15/21.
//

#ifndef S21_PA04_MIKECUZZO_GRANTAYERS_GRAPHENGINE_H
#define S21_PA04_MIKECUZZO_GRANTAYERS_GRAPHENGINE_H

#include "iostream"
#include "fstream"
#include <stdio.h>
#include <boost/graph/adjacency_list.hpp>
#include "Kruskals.h"
#include "Prims.h"
#include "chrono"
#include "boost/graph/graph_utility.hpp"
#include "Python.h"
#include <filesystem>

using namespace std;
using namespace boost;
using namespace chrono;

class GraphEngine {
public:
    GraphEngine(int,char**);
    void generateGraph();
    adjacency_list<listS, vecS, undirectedS>  readFile(string);
    void algTiming(adjacency_list<listS, vecS, undirectedS>);
private:
    typedef adjacency_list<listS, vecS, undirectedS> Graph;
    void createGraphs();
    void recordStats(int nodes, int edges, int kruskal, int prim);
    string flag;
    string path;
};


#endif //S21_PA04_MIKECUZZO_GRANTAYERS_GRAPHENGINE_H
