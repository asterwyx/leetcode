/*
 * @lc app=leetcode.cn id=1287 lang=cpp
 * @lcpr version=30204
 *
 * [1287] 有序数组中出现次数超过25%的元素
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int curN = arr[0];
        int curCount = 0;
        int n = arr.size();
        for (auto i : arr) {
            if (i == curN) {
                curCount++;
                if (curCount > n / 4) {
                    return curN;
                }
            } else {
                curN = i;
                curCount = 1;
            }
        }
        return curN;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,2,6,6,6,6,7,10]\n
// @lcpr case=end

 */

