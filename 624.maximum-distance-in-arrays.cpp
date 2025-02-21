/*
 * @lc app=leetcode.cn id=624 lang=cpp
 * @lcpr version=30204
 *
 * [624] 数组列表中的最大距离
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
    int maxDistance(vector<vector<int>>& arrays) {
        int min = 10e5;
        int minI = 0;
        int maxI = 0;
        int max = -10e5;
        for (int i = 0; i < arrays.size(); i++) {
            if (arrays[i].front() < min) {
                min = arrays[i].front();
                minI = i;
            }
            if (arrays[i].back() > max) {
                max = arrays[i].back();
                maxI = i;
            }
        }
        if (minI != maxI) {
            return max - min;
        } else {
            int res = 0;
            for (int i = 0; i < arrays.size(); i++) {
                if (i != minI) {
                    res = std::max(res, abs(arrays[i].front() - max));
                    res = std::max(res, abs(arrays[i].back() - min));
                }
            }
            return res;
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,3],[4,5],[1,2,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[1],[1]]\n
// @lcpr case=end

 */

