#include <iostream>
#include "GraphEngine.h"

using namespace std;

// command line args for testing (mike):
// -b /home/mcuzzo/Desktop/data/

int main(int argc, char** argv) {
    string output_modifier = "";
    string path = "";

    switch(argc) {
        case 3:
            path = argv[2];
            output_modifier = argv[1];
            break;
        case 2:
            output_modifier = argv[1];
            break;
        default:
            output_modifier = "-f";
            break;
    }

    GraphEngine g = GraphEngine(output_modifier, path);
    return 0;
}
