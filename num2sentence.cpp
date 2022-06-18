#include <bits/stdc++.h>
using namespace std;

static const string units[] = {"Thousand", "Million", "Billion"};
static const string base[] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
static const string teens[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Nineteen"};
static const string ties[] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

class Solution {
public:
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";
        stack<string> words;
        string result;
        int section = 0; // this lead to unit change
        int grp_three;
        int pushed;
        int bpos, tpos, hpos; // three pos in group three
        for (; num > 0; ++section, num /= 1000) {
            grp_three = num % 1000;
            if (grp_three == 0) {
                continue;
            }
            if (section) {
                words.push(units[section - 1]);
            }
            bpos = grp_three % 10;
            tpos = (grp_three / 10) % 10;
            hpos = grp_three / 100;
            if (bpos != 0) {
                words.push(base[bpos - 1]);
            }
            if (tpos == 1) {
                if (bpos != 0)
                    words.pop();
                words.push(teens[grp_three % 100 - 10]);
            } else if(tpos != 0) {
                if (bpos == 0) {
                    words.pop();
                }
                words.push(ties[tpos - 2]);             
            }
            if (hpos != 0) {
                words.push("Hundred");
                words.push(base[hpos - 1]);
            }
        }
        while (!words.empty()) {
            result += words.top() + " ";
            words.pop();
        }
        result.pop_back();
        return result;
    }
};

int main() {
    Solution s;
    cout << s.numberToWords(10) << endl;
    return 0;
}