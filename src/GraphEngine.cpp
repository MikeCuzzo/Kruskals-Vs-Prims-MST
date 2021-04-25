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
    inFile.open("../data/graph/text/graph1.txt");
    // record all input and put it into a graph
    string buffer;
    Graph g;
    getline(inFile, buffer);
    int size = stoi(buffer);
    for (int i = 0; i < size; i++) {
        getline(inFile, buffer, '\n');
        char edge1 = buffer[buffer.find('(') + 1];
        char edge2 = buffer[buffer.find(')') - 1];
        add_edge(edge1 - 48, edge2 - 48, g);
    }
    // print_graph(g);
    inFile.close();
    algTiming(g);
}

void GraphEngine::algTiming(adjacency_list<listS, vecS, undirectedS> g) {
    // times Kruskal's
    int executionTime = 0;
    auto start = std::chrono::high_resolution_clock::now();
    Kruskals k = Kruskals(g);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    executionTime = duration.count();
    cout << "Kruskal's with " << num_vertices(g) << " verticies and " << num_edges(g) << " edges: " <<
    executionTime << " microseconds" << endl;

    // times Prim's
    executionTime = 0;
    start = std::chrono::high_resolution_clock::now();
    Prims p = Prims(g);
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    executionTime = duration.count();
    cout << "Prim's with " << num_vertices(g) << " verticies and " << num_edges(g) << " edges: " <<
         executionTime << " microseconds" << endl;
}