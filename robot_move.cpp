#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // return how many cubes
    int dfs(const int& threshold, const int& rows, const int& cols, vector<vector<bool>> &vis, int i, int j) {
        if (i < 0 || j < 0 || i >= rows || i >= cols || vis[i][j]) return 0;
        vis[i][j] = true;
        int sum = 0, tmpi = i, tmpj = j;
        while (tmpi) {
            sum += tmpi % 10;
            tmpi /= 10;
        }
        while (tmpj) {
            sum += tmpj % 10;
            tmpj /= 10;
        }
        if (sum > threshold)
            return 0;
        else
            return dfs(threshold, rows, cols, vis, i + 1, j) +
                   dfs(threshold, rows, cols, vis, i - 1, j) +
                   dfs(threshold, rows, cols, vis, i, j + 1) +
                   dfs(threshold, rows, cols, vis, i, j - 1) + 1;
    }
    
    int movingCount(int threshold, int rows, int cols) {
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));
        return dfs(threshold, rows, cols, vis, 0, 0);
    }
};


int main() {
    Solution solution;
    cout << solution.movingCount(15, 20, 20) << endl;
    return 0;
}