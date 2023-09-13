/*
 * main.cpp
 *
 * Includes the main() function for the graph BFS project.
 *
 * This code creates the executable run-main.
*/

#include <iostream>
#include <vector>
#include "graph.h"

using namespace std;

int main() {
    
    graph g(10);
    g.add_edge(4, 6);
    g.add_edge(6, 2);
    g.add_edge(9, 3);
    g.add_edge(3, 7);
    g.add_edge(7, 3);
    g.add_edge(7, 4);
    g.add_edge(8, 1);
    g.add_edge(9, 2);
    g.add_edge(1, 7);
    g.add_edge(0, 7);
    g.add_edge(3, 0);
    g.add_edge(3, 6);
    g.add_edge(4, 5);
    g.add_edge(4, 1);
    g.add_edge(9, 1);
    g.add_edge(0, 9);
    g.add_edge(7, 9);

    vector<int> list;
    list = g.find_shortest_path(6,0);
    
    for (int i = 0; i < list.size(); i++){
        cout << "Node: " << list.at(i) << endl;
    }

    list = g.find_shortest_path(8,5);
    
    for (int i = 0; i < list.size(); i++){
        cout << "Node: " << list.at(i) << endl;
    }

    list = g.find_shortest_path(1,2);
    
    for (int i = 0; i < list.size(); i++){
        cout << "Node: " << list.at(i) << endl;
    }

    return 0;
}
