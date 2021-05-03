//
// Created by mcuzzo on 4/15/21.
//

#include "GraphEngine.h"

GraphEngine::GraphEngine(string output_modifier, string p) {
    // Checking if path is empty or not
    if (p == "") {
        path = "../data/graph/text/";
        createGraphs();
    } else {
        path = p;
    }

    // Checking if output is empty or not
    if (output_modifier == ""){
        flag = "-f";
    } else {
        flag = output_modifier;
    }

    // Generating the graph
    generateGraph();
}

void GraphEngine::generateGraph() {
    if (path.back() == '/') {
        using filesystem::directory_iterator;
        for(auto& i: directory_iterator(path)){
            Graph toTest = ReadFile(i.path());
            algTiming(toTest);
        }
    }
    else {
        Graph toTest = ReadFile(path);
        algTiming(toTest);
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
    long long kruskalWeight = k.get_total_weight();
    int kruskalEdges = k.get_total_edges();
    outputPerformance("Kruskal", kruskalEdges, kruskalWeight);

    // times Prim's
    int primTime = 0;
    start = std::chrono::high_resolution_clock::now();
    Prims p = Prims(g);
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    primTime = duration.count();
    long long primsWeight = p.get_total_weight();
    int primsEdges = p.get_total_edges();
    outputPerformance("Prims", primsEdges, primsWeight);     

    // Writing stats to file
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

GraphEngine::Graph GraphEngine::ReadFile(string p){
    ifstream inFile;
    inFile.open(p);
    string buffer = "";
    Graph g;
    while(inFile.good()) {
        getline(inFile, buffer, ' ');
        string edge1 = buffer;
        getline(inFile, buffer, ' ');
        string edge2 = buffer;
        getline(inFile, buffer, '\n');
        string weight = buffer.substr(0,buffer.size()-1);
        
        if (edge1 != ""){
            add_edge(stoi(edge1), stoi(edge2), stoi(weight), g);
        }
        else {
            break;
        }
    }

    inFile.close();

    return g;
}


void GraphEngine::recordStats(int nodes, int edges, int kruskal, int prim) {
    ofstream File_Writer;
    
    // writing to the csv file
    File_Writer.open("../data/timing/stats.csv", ios::app);
    File_Writer << nodes << "," << edges << "," << kruskal << "," << prim << "\n";
    File_Writer.close();
}

void GraphEngine::outputPerformance(string type, int total_edges, long long total_weight){
    cout << type << ": edges[" << total_edges << "] weight[" << total_weight << "]\n";
}

