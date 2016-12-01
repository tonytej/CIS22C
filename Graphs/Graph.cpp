/*
Antony Tejakusuma
CIS22C
Graph.cpp
*/

#include "Graph.h"
#include <queue>

Graph::Graph(int n){
    for(unsigned i = 0; i < n; i++){
            color[i] = 'W';
            distance[i] = -1;
            parent[i] = 0;
        }
}

Graph::~Graph(){}

int Graph::get_num_edges(){
    int sum;
    for(auto & i : adj){
        sum += i.get_length();
    }
    return sum;
}

int Graph::get_num_vertices(){
    return adj.size();
}

bool Graph::is_empty(){
    return (adj.size() == 0);
}

void Graph::addEdge(int u, int v){
    adj[u].add_end(v);
}

void Graph::print_graph(ostream& output){
    for(unsigned i = 0; i < adj.size(); i++){
        if(!is_empty()){
            output << i << ": " << adj[i].print();
        }
    }
}

void Graph::print_BFS(ostream& output){
    output << "v\tc\tp\td" << endl;
    for(unsigned i = 0; i < adj.size(); i++){
        if(!is_empty()){
            output << i << "\t" << color[i] << "\t" <<  parent[i] << "\t" <<  distance[i] << endl;
        }
    }
}

void Graph::breadth_first_search(int source){
    queue<int> q;
    for(unsigned i = 0; i < adj.size(); i++){
        color[i] = 'W';
        distance[i] = -1;
        parent[i] = 0;
    }
    color[source] = 'G';
    distance[source] = 0;
    q.push(source);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        adj[x].begin_cursor();
        while(!adj[x].off_end()){
            if (color[adj[x].get_cursor()] == 'W'){
                color[adj[x].get_cursor()] = 'G';
                distance[adj[x].get_cursor()] = distance[x] + 1;
                parent[adj[x].get_cursor()] = x;
                q.push(adj[x].get_cursor());
            }
            adj[x].move_cursor();
        }
        color[x] = 'B';
    }

}

void Graph::print_path(int source, int destination, ostream output){
    if (destination == source){
        output << source << endl;
    } else if (parent[destination] == 0){
        output << "No path from " << source << " to " << destination << " exists" << endl;
    } else {
        print_path(source, parent[destination], output);
    }

}












