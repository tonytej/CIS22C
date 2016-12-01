/*
Antony Tejakusuma
CIS22C
BFS.cpp
*/

#include <fstream>
#include "Graph.cpp"
#include <sstream>
#include <iostream>
using namespace std;

int main(){
    ifstream fin("infile.txt");
    if(fin.fail()){
        cout << "Input file failed to open.\n";
        exit(-1);
    }
    ofstream fout("outfile.txt");
    int size;
    fin >> size;
    Graph g(size);
    int a, b;
    while(fin >> a >> b){
        if(a == 0 and b == 0){
            break;
        }
        g.addEdge(a, b);
    }
    g.print_graph(fout);
    
    while(fin >> a >> b){
        if(a == 0 and b == 0){
            break;
        }
        g.breadth_first_search(a);
        g.calculate_distance(a, b, fout);
        fout << "A shortest " << a << "-" << b << " path is: ";
        g.print_path(a, b, fout);
        fout << endl; 
    }
}
