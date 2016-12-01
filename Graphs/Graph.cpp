/*
Antony Tejakusuma
CIS22C
Graph.cpp
*/

#include "Graph.h"
#include <queue>

using namespace std;

Graph::Graph(int n){
    List<int> L;
    for(int i = 0; i < n + 1; ++i){
        adj.push_back(L);
        color.push_back('W');
        distance.push_back(-1);
        parent.push_back(0);
    }
}

Graph::~Graph(){}

int Graph::get_num_edges(){
    int sum;
    for(int i = 0; i < adj.size(); ++i){
        sum += adj[i].get_length();
    }
    return sum/2;
}

int Graph::get_num_vertices(){
    return adj.size();
}

bool Graph::is_empty(){
    return (adj.size() == 0);
}

void Graph::addEdge(int u, int v){
    adj[u].add_end(v);
    adj[v].add_end(u);
}

void Graph::print_graph(ostream& output){
    for(unsigned i = 0; i < adj.size(); i++){
        if(!adj[i].is_empty()){
            output << i << ": "; 
            adj[i].begin_cursor();
            while(!adj[i].off_end()){
                output << adj[i].get_cursor() << " ";
                adj[i].move_cursor();
            }
            output << endl;
        }
    }
}

void Graph::print_BFS(ostream& output){
    output << "v\tc\tp\td" << endl;
    for(unsigned i = 0; i < adj.size(); i++){
        if(!adj[i].is_empty()){
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

void Graph::print_path(int source, int destination, ostream& output){
    if (destination == source){
        output << source << " ";
    } else if (parent[destination] == 0){
        output << "No path from " << source << " to " << destination << " exists" << endl;
    } else {
        print_path(source, parent[destination], output);
        output << destination << " ";
    }
}

void Graph::calculate_distance(int source, int destination, ostream& output){
    if (distance[destination] == -1){
        output << "The distance from " << source << " to " << destination << " is infinity" << endl; 
    } else {
        output << "The distance from " << source << " to " << destination << " is " <<  distance[destination] << endl;
    }
}
    










