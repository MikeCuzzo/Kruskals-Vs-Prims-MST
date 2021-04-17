//
// Created by mcuzzo on 4/15/21.
//

#include "GraphEngine.h"

GraphEngine::GraphEngine(){
    generateGraph();
}

void GraphEngine::generateGraph(){
    //runs python script to create graph in a file
    system("python3 ../python/creategraph.py");

    ifstream inFile;
    inFile.open("../data/input.txt");
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