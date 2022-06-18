#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int InversePairs(vector<int> data) {
        return MergeInversePairs(data, 0, data.size() - 1);
    }
private:
    int MergeInversePairs(vector<int> &a, int low, int high) {
        if (low >= high) {
            return 0;
        }
        int mid = (high - low) / 2;
        vector<int> copy(a.begin() + low, a.begin() + high + 1);
        int inversePair = MergeInversePairs(copy, 0, mid) + MergeInversePairs(copy, mid + 1, high - low);
        inversePair %= 1000000007;
        int i = 0, j = mid + 1, cursor = low;
        while (i <= mid && j <= (high - low)) {
            if (copy[i] <= copy[j]) {
                a[cursor++] = copy[i++];
            } else {
                a[cursor++] = copy[j++];
                inversePair += mid - i + 1;
            }
        }
        while (i <= mid) {
            a[cursor++] = copy[i++];
        }
        while (j <= (high - low)) {
            a[cursor++] = copy[j++];
        }
        return inversePair;
    }
};

int main() {
    vector<int> arr {364,637,341,406,747,995,234,971,571,219,993,407,416,366,315,301,601,650,418,355,460,505,360,965,516,648,727,667,465,849,455,181,486,149,588,233,144,174,557,67,746,550,474,162,268,142,463,221,882,576,604,739,288,569,256,936,275,401,497,82,935,983,583,523,697,478,147,795,380,973,958,115,773,870,259,655,446,863,735,784,3,671,433,630,425,930,64,266,235,187,284,665,874,80,45,848,38,811,267,575};
    vector<int> data {3, 2, 6, 5, 1, 7, 0, 4};
    Solution solution;
    cout << solution.InversePairs(arr) << endl;
    return 0;
}