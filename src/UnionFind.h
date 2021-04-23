//
// Created by mcuzzo on 4/23/21.
//

#ifndef S21_PA04_MIKECUZZO_GRANTAYERS_UNIONFIND_H
#define S21_PA04_MIKECUZZO_GRANTAYERS_UNIONFIND_H

#include <boost/graph/adjacency_list.hpp>

using namespace std;
using namespace boost;


class UnionFind {
public:
    UnionFind(adjacency_list<listS, vecS, undirectedS>);
    bool isCycle();
    int find();
    void Union();
private:
    typedef adjacency_list<listS, vecS, undirectedS> Graph;
    Graph g;
    typedef Graph::edge_descriptor Edge;
    typedef graph_traits<Graph>::vertex_descriptor Vertex;
    vector<boost::tuple<int,int>> subsets;
};


#endif //S21_PA04_MIKECUZZO_GRANTAYERS_UNIONFIND_H
