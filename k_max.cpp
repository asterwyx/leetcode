#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    #define MIN 1L << 63
    int thirdMax(vector<int>& nums) {
        long max = MIN, sec_max = MIN, third_max = MIN;
        bool update = false;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > max){
                third_max = sec_max;
                sec_max = max;
                max = nums[i];
            } else if (nums[i] > sec_max && nums[i] < max ) {
                third_max = sec_max;
                sec_max = nums[i];
            } else if (nums[i] >= third_max && nums[i] < sec_max) {
                third_max = nums[i];
            }
        }
        return third_max != MIN ? third_max : max;
    }
};

int main () {
    vector<int> v{1,2,2,5,3,5};
    Solution s;
    auto n = s.thirdMax(v);
    cout << n << endl;
    return 0;
}