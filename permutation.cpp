#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(const string& s, vector<bool> &visited, int i, int n, string& perm) {
        if (i == n) {
            m_perm.push_back(perm);
            return;
        }
        for (int j = 0; j < n; ++j) {
            if (visited[j] || (j > 0 && !visited[j - 1] && s[j - 1] == s[j])) {
                // if s[j] has been visited or 
                continue;
            }
            visited[j] = true;
            perm.push_back(s[j]); // try fill
            backtrack(s, visited, i + 1, n, perm); // fill next
            // try another, pop filled
            perm.pop_back();
            visited[j] = false;
        }
    }

    vector<string> permutation(string s) {
        // sort to ensure non duplicate
        sort(s.begin(), s.end());
        vector<bool> vis(s.length(), false);
        string perm;
        backtrack(s, vis, 0, s.length(), perm);
        return m_perm;
    }

private:
    vector<string> m_perm;
};

int main() {
    Solution solution;
    for (auto &s : solution.permutation("aabb")) {
        cout << s << endl;
    }
    return 0;
}