//
// Created by mcuzzo on 4/15/21.
//

#include "GraphEngine.h"

GraphEngine::GraphEngine() {
    generateGraph();
}

void GraphEngine::generateGraph() {
    //runs python script to create graph in a file

    // number of nodes
    for (int n = 2; n < n + 4; n++) {
        // number of edges
        for (int e = 2; e < e + 3; e++) {

            string command = "python3 ../python/creategraph.py " + to_string(n) + " " + to_string(e);

            system(command.c_str());

            ifstream inFile;
            inFile.open("../data/input.txt");
            // record all input and put it into a graph
            inFile.close();
            algTiming();
        }
    }
}

void GraphEngine::algTiming() {
    // times Kruskal's
    int executionTime = 0;
    auto start = std::chrono::high_resolution_clock::now();
    Kruskals k = Kruskals(g);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    executionTime = duration.count();

    // times Prim's
    executionTime = 0;
    start = std::chrono::high_resolution_clock::now();
    Prims p = Prims(g);
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    executionTime = duration.count();
}