#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;


void DFS( int u, vector<bool> &visited ) {
    visited [u] = true;
    cout << u << " " << "\n";

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ifstream inFile("nay no va gi do/practice/practice/data-structures/graph/graph.txt");
    int u; int v; int maxNode = 0;
    while ( inFile >> u >> v ){
        maxNode = max ({u, v, maxNode});
    }
    int size = maxNode + 1;
    // ma trận kề
    inFile.clear();
    inFile.seekg(0,ios::beg);
    string line;
    vector<bool> visited(size, false); 
    
    // danh sách kề 
    vector<vector<int>> List (size);
    while ( getline(inFile,line) ){
        stringstream ss (line);
        int from, to;
        ss >> from >> to;
        List[from].push_back(to);
    }   

    


    return 0;
}