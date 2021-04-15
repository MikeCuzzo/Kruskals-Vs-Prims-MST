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
