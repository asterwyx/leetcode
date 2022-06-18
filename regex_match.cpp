#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param str string字符串 
     * @param pattern string字符串 
     * @return bool布尔型
     */
    bool match(string str, string pattern) {
        // write code here
        if (str.empty() && pattern.empty()) {
            return true;
        } else if(!str.empty() && pattern.empty()) {
            return false;
        } else if(str.empty() && !pattern.empty()) {
            int len  = pattern.length();
            while (!pattern.empty() && pattern.back() == '*') {
                pattern.pop_back();
                pattern.pop_back();
            }
            return pattern.empty();
        } else {
            if(pattern.back() == '*') {
                pattern.pop_back();
                char c;
                // if '*', sub match
                if (pattern.back() == '.') {
                    return true;
                } else {
                    c = pattern.back();
                    pattern.pop_back();
                }
                bool matched = false, next = true;
                do {
                    matched = match(str, pattern);
                    if (c == str.back()) {
                        next = true;
                        str.pop_back();
                    } else {
                        next = false;
                    }
                } while (!matched && next);
                return matched;
            } else {
                // if '.' or equal, go on
                if (pattern.back() == '.' || str.back() == pattern.back()) {
                    str.pop_back();
                    pattern.pop_back();
                    return match(str, pattern);
                } else {
                    return false;
                }
                
            }
        }
    }
};

int main() {
    Solution solution;
    cout << solution.match("aaca", "ab*a*c*a") << endl;
    return 0;
}