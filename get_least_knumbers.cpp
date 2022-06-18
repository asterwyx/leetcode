#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        // use quicksort
        vector<int> res;
        if (input.empty() || k == 0) {
            return res;
        }
        return quickFindK(input, 0, input.size() - 1, k);
    }
    
    vector<int> quickFindK(vector<int> &a, int l, int r, int k) {
        int pivot = a[l];
        int i = l, j = r;
        while (l < r) {
            while (l < r && a[r] >= pivot) {
                r--;
            }
            if (l < r) {
                a[l] = a[r];
                l++;
            }
            while (l < r && a[l] < pivot) {
                l++;
            }
            if (l < r) {
                a[r] = a[l];
                r--;
            }
        }
        a[l] = pivot;
        if (l == k - 1 || l == k) {
            return vector<int>(a.begin(), a.begin() + k);
        } else if (l > k) {
            return quickFindK(a, i, l - 1, k);
        } else {
            return quickFindK(a, l + 1, j, k);
        }
    }
    
};

int main() {
    Solution solution;
    for (auto &n : solution.GetLeastNumbers_Solution({4,5,1,6,2,7,3,8}, 8)) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}