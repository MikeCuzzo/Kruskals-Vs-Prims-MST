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
            // generates graph from python
            // going to need to import a pythong library
            // this only works on my machine and probably not the grader's
            string command = "python3 ../python/creategraph.py " + to_string(n) + " " + to_string(e);
            system(command.c_str());

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
    }
}

void GraphEngine::algTiming(adjacency_list<listS, vecS, undirectedS> g) {
    // times Kruskal's
    int executionTime = 0;
    auto start = std::chrono::high_resolution_clock::now();
    Kruskals k = Kruskals(g);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    executionTime = duration.count();
    cout << "Kruskal's with " << num_vertices(g) << " verticies and _ density: " <<
    executionTime << " microseconds" << endl;

    // times Prim's
    executionTime = 0;
    start = std::chrono::high_resolution_clock::now();
    Prims p = Prims(g);
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    executionTime = duration.count();
    cout << "Prim's with " << num_vertices(g) << " verticies and _ density: " <<
         executionTime << " microseconds" << endl;
}