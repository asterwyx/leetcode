#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    #define DEF_ELE -1000000
    bool VerifySquenceOfBST(vector<int> sequence) {
        /* we use recursive verify*/
        // if a BST can be restored from the sequence use the characteristic of post order
        if (sequence.empty()) {
            return false;
        }
        int left, right;
        return RestoreBST(&sequence[0], sequence.size(), left, right);
    }
    
    bool RestoreBST(int seq[], int len, int &minimum, int &maximum) {
        if (len == 0) {
            return true;
        } else {
            int root = seq[len - 1]; // post order, get root element
            int i;
            for (i = len - 2; i >= 0; --i) {
                if (seq[i] < root) {
                    break;
                }
            }
            int left_min = DEF_ELE, left_max = DEF_ELE, right_min = DEF_ELE, right_max = DEF_ELE;
            bool left_res = RestoreBST(seq, i + 1, left_min, left_max);
            bool right_res = RestoreBST(seq + i + 1, len - i - 2, right_min, right_max);
            if (left_res && right_res) {
                if (i < 0) {
                    // left tree is null
                    minimum = root;
                } else {
                    minimum = left_min;
                    if (left_max > root)
                        return false;
                }
                if (i >= (len - 2)) {
                    // right tree is null
                    maximum = root;
                } else {
                    maximum = right_max;
                    if (right_min < root)
                        return false;
                }
                return true;
            } else {
                return false;
            }
        }
    }
};

int main() {
    Solution solution;
    vector<int> data = {7,4,9,3,8,11,12,10};
    cout << solution.VerifySquenceOfBST(data) << endl;
    return 0;
}

