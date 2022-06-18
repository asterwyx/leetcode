/* shortest path problem, Dijkstra algorithm (A greedy algorithm) */
#include <bits/stdc++.h>
using namespace std;

// Dijkstra algorithm usually use adjacent matrix
int dijkstra(vector<int> &shortest_path, vector<vector<int>> &adjac_matrix, int s) {
    // 1. initialize shortest path
    for (int i = 0; i < shortest_path.size(); ++i) {
        shortest_path[i] = adjac_matrix[s][i];
    }
    
}



int main() {

    return 0;
}
