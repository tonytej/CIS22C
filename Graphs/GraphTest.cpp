/*
Antony Tejakusuma
CIS22C
GraphTest.cpp
*/

#include "Graph.cpp"
#include <iostream>

using namespace std;

int main(){
    Graph g(6);
    if(g.is_empty()){
        cout << "Graph is empty" << endl;
    } else {
        cout << "Graph is not empty" << endl;
    }

    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);

    cout << "Edges: " << g.get_num_edges() << endl;
    cout << "Vertices: " << g.get_num_vertices() << endl;
    
    if(g.is_empty()){
        cout << "Graph is empty" << endl;
    } else {
        cout << "Graph is not empty" << endl;
    }
    
    cout << endl;

    g.print_graph(cout);

    cout << endl;
    cout << "Executing BFS with source 1:" << endl;
    g.breadth_first_search(1);
    g.print_BFS(cout);
    cout << "The distance from 1 to 5 is ";
    g.calculate_distance(1, 5, cout);
    cout << "A shortest 1-5 path is: ";
    g.print_path(1, 5, cout);
    cout << endl << endl;

    cout << "Executing BFS with source 2:" << endl;
    g.breadth_first_search(2);
    g.print_BFS(cout);
    cout << "The distance from 2 to 3 is ";
    g.calculate_distance(2, 3, cout);
    cout << "A shortest 2-3 path is: ";
    g.print_path(2, 3, cout);
    cout << endl << endl;
    
    cout << "Executing BFS with source 3:" << endl;
    g.breadth_first_search(3);
    g.print_BFS(cout);
    cout << "The distance from 3 to 6 is ";
    g.calculate_distance(3, 6, cout);
    cout << "A shortest 3-6 path is: ";
    g.print_path(3, 6, cout);
    cout << endl;
}
/*
Graph is not empty
Edges: 8
Vertices: 7
Graph is not empty

1: 2 3 
2: 1 4 5 6 
3: 1 4 
4: 2 3 5 
5: 2 4 6 
6: 2 5 

Executing BFS with source 1:
v   c   p   d
1   B   0   0
2   B   1   1
3   B   1   1
4   B   2   2
5   B   2   2
6   B   2   2
The distance from 1 to 5 is The distance from 1 to 5 is 2
A shortest 1-5 path is: 1 2 5 

Executing BFS with source 2:
v   c   p   d
1   B   2   1
2   B   0   0
3   B   1   2
4   B   2   1
5   B   2   1
6   B   2   1
The distance from 2 to 3 is The distance from 2 to 3 is 2
A shortest 2-3 path is: 2 1 3 

Executing BFS with source 3:
v   c   p   d
1   B   3   1
2   B   1   2
3   B   0   0
4   B   3   1
5   B   4   2
6   B   2   3
The distance from 3 to 6 is The distance from 3 to 6 is 3
A shortest 3-6 path is: 3 1 2 6 
*/
