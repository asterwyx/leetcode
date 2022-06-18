#include <bits/stdc++.h>
using namespace std;
vector<string> desc_arr({"1"});
class Solution {
public:
    string countAndSay(int n) {
        if (n > desc_arr.size()) {
            // from desc_arr.size() + 1 to n need to be calculated
            int len = n - desc_arr.size();
            char c;
            int count;
            string last;
            while (len--) {
                last = desc_arr.back();
                desc_arr.emplace_back();
                string &now = desc_arr.back();
                c = last[0];
                count = 0;
                for (int i = 0; i < last.length(); ++i) {
                    if (last[i] == c) {
                        count++;
                    } else {
                        now += to_string(count) + c;
                        c = last[i];
                        count = 1;
                    }
                }
                now += to_string(count) + c;
            }
        }
        return desc_arr[n - 1];
    }
};
int main() {
    Solution solution;
    cout << solution.countAndSay(1) << endl;
    cout << solution.countAndSay(2) << endl;
    cout << solution.countAndSay(3) << endl;
    cout << solution.countAndSay(4) << endl;
    cout << solution.countAndSay(5) << endl;
    cout << solution.countAndSay(6) << endl;
    cout << solution.countAndSay(7) << endl;
    cout << solution.countAndSay(8) << endl;
    return 0;
}