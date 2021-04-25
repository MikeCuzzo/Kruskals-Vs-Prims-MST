//
// Created by mcuzzo on 4/15/21.
//

#include "GraphEngine.h"

GraphEngine::GraphEngine() {
    generateGraph();
}

void GraphEngine::generateGraph() {
    //runs python script to create graph in a file
    Py_Initialize();

    PyRun_SimpleString("python3 ./python/creategraph.py");

    Py_Finalize();


    ifstream inFile;
    inFile.open("../data/input.txt");
    // record all input and put it into a graph
    string buffer;
    Graph g;
    while(inFile.good()) {
        getline(inFile, buffer,':');
        char edge1 = buffer[buffer.find('(')+1];
        char edge2 = buffer[buffer.find(')')-1];
        if(buffer[0] != '{')
            add_edge(edge1-48,edge2-48,g);
    }
    print_graph(g);
    inFile.close();
            // algTiming();
}

void GraphEngine::algTiming(adjacency_list<listS, vecS, undirectedS> g) {
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