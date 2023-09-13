/*
 * graph.cpp
 *
 * Method definitions for the graph class.
 *
 * Author: <your name here>
 */

#include "graph.h"
#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

graph::graph(int vertex_count){
    Nodes.resize(vertex_count);
    size = vertex_count;
    visited.resize(size);
}

void graph::add_edge(int from, int to){
    Nodes[from].push_back(to);
}

void graph::set_visited(int node){
    //cout << "there" << endl;
    visited.at(node) = true;
    //cout << "ahh" << endl;
}

bool graph::check_visited(int node){
    //cout << "here" << endl;
    if (visited[node]){
        return true;
    }
    return false;
}

void graph::clear_visited(){
    //cout << "1" << endl;
    visited.clear();
    //cout << "2" << endl;
}

int graph::neighbor(int num){
    // if (Nodes[num].size() == 0){
    //     cout << "Empty" << endl;
    // }
    // for (int i = 0; i < Nodes[num].size(); i++){
    //     cout << Nodes[num][i] << endl;
    // }
    return Nodes[num][0];
}

vector<int> graph::find_shortest_path(int from, int to){
    clear_visited();
    visited.resize(size);

    //cout << "Visited start" << endl;
    for (int i = 0; i < visited.size(); i++){
        //cout << visited[i] << endl;
    }
    //cout << "Visited end" << endl;

    //cout << "3" << endl;

    graph revTree(size);

    //cout << "4" << endl;

    queue<int> Q;
    set_visited(from);
    Q.push(from);

    //cout << "5" << endl;

    while (!(Q.empty()) && !(check_visited(to))){
        int val = Q.front();
        Q.pop();

        for (size_t i = 0; i < Nodes[val].size(); i++){
            //cout << "1" << endl;
            if (!(check_visited(Nodes[val][i]))){
                //cout << "ahhhhhhhh" << endl;
                //cout << "2" << endl;
                Q.push(Nodes[val][i]);
                //cout << "3" << endl;
                set_visited(Nodes[val][i]);
                //cout << "4" << endl;
                //cout << "ahh: " << Nodes.at(val).at(i) << endl;
                //cout << "ooh: " << val << endl;
                revTree.add_edge(Nodes[val][i], val);
                //cout << "5" << endl;
                if (Nodes[val][i] == to){
                    break;
                }
            }
        }

    }

    //cout << "6" << endl;

    vector<int> list;

    //cout << "7" << endl;

    if (check_visited(to)){
        //cout << "in 1" << endl;
        //cout << "here" << endl;
        list.push_back(to);
        //cout << "begin" << endl;
        while (to != from){
            //cout << "in in 1" << endl;
            //cout << to << endl;
            //cout << revTree.neighbor(to) << endl;
            to = revTree.neighbor(to);
            //cout << "in in 2" << endl;
            list.push_back(to);
            //cout << "in in 3" << endl;
        }
        //cout << "end" << endl;
    }

    //cout << "8" << endl;

    reverse(list.begin(), list.end());
    return list;
}