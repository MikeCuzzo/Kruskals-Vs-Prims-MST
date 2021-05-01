//
// Created by mcuzzo on 4/15/21.
//

#include "GraphEngine.h"

GraphEngine::GraphEngine(int argc, char **argv) {
    if (argc > 1) {
        flag = argv[1];
        path = argv[2];
    } else {
        path = "../data/graph/text/";
        // Runs Python file
        createGraphs();
    }
    generateGraph();
}

void GraphEngine::generateGraph() {
    // Getting the number of graphs from the data section
    using filesystem::directory_iterator;
    ifstream inFile;

       for(auto& i: directory_iterator(path)) {
        // Create the path to the first graph
        // Open the path
        inFile.open(i.path());

        // record all input and put it into a graph
        string buffer = "";
        getline(inFile, buffer, '\n');
        Graph g;
        while(inFile.good()) {
            getline(inFile, buffer, ' ');
            string edge1 = buffer;
            getline(inFile, buffer, ' ');
            string edge2 = buffer;
            getline(inFile, buffer, '\n');
            string weight = buffer.substr(0,buffer.size()-1);

            if(edge1 != "")
                add_edge(stoi(edge1), stoi(edge2), stoi(weight), g);
            else
                break;
        }
        inFile.close();
        algTiming(g);
    }
}

void GraphEngine::algTiming(adjacency_list<listS, vecS,undirectedS,no_property,property<edge_weight_t, int>> g) {
    // times Kruskal's
    int kruskalTime = 0;
    auto start = std::chrono::high_resolution_clock::now();
    Kruskals k = Kruskals(g);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    kruskalTime = duration.count();
    cout << "Kruskal's with " << num_vertices(g) << " verticies and " << num_edges(g) << " edges: " <<
         kruskalTime << " microseconds" << endl;

    // times Prim's
    int primTime = 0;
    start = std::chrono::high_resolution_clock::now();
    Prims p = Prims(g);
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    primTime = duration.count();
    cout << "Prim's with " << num_vertices(g) << " verticies and " << num_edges(g) << " edges: " <<
         primTime << " microseconds" << endl;

    // Writing to file
    recordStats(num_vertices(g), num_edges(g), kruskalTime, primTime);
}


void GraphEngine::createGraphs() {
    //runs python script to create graph in a file
    Py_Initialize();
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('../python')");

    PyObject *obj = Py_BuildValue("s", "../python/creategraph.py");
    FILE *file = _Py_fopen_obj(obj, "r+");
    if (file != NULL) {
        PyRun_SimpleFile(file, "creategraph.py");
    }
    Py_Finalize();
}


void GraphEngine::recordStats(int nodes, int edges, int kruskal, int prim) {
    ofstream File_Writer;
    File_Writer.open("../data/timing/stats.csv", ios::app);
    File_Writer << nodes << "," << edges << "," << kruskal << "," << prim << "\n";
    File_Writer.close();
}
