/*
 * graph.h
 *
 * Declaration of the graph class.
 * 
 * Author: <your name here>
 */

#ifndef _GRAPH_BFS_H
#define _GRAPH_BFS_H

#include <vector>

using namespace std;

class graph {
public:
    graph(int vertex_count);
    void add_edge(int from, int to);
    vector<int> find_shortest_path(int from, int to);
    int neighbor(int num);

private:
    vector<vector<int>> Nodes;
    vector<bool> visited;
    void set_visited(int node);
    bool check_visited(int node);
    void clear_visited();
    int size;
};

#endif
