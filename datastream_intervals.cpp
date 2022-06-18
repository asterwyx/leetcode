#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class SummaryRanges {
public:
    SummaryRanges() {

    }
    
    void addNum(int val) {
        vector<vector<int>>::iterator it, prev = m_intervals.end();
        // find if val exist in or adjacent to current intervals
        // if exist or adjacent, save val in the interval, update interval, save it.
        // if find next, merge two intervals
        bool found = false;
        for (it = m_intervals.begin(); it != m_intervals.end(); ++it) {
            if (val >= (it->front() - 1) && val <= (it->back() + 1)) {
                // save val
                it->front() = min(it->front(), val);
                it->back() = max(it->back(), val);
                if (!found) {
                    // prev not accessed, just save
                    found = true;
                    prev = it;
                } else {
                    // merge two, erase larger
                    prev->back() = it->back();
                    auto diff = it - prev;
                    it = m_intervals.erase(it);
                    prev = it - diff;
                    if (it == m_intervals.end())
                        break;
                } 
            } else if (val < (it->front() - 1)) {
                break;
            }
        }
        if (!found) {
            // create a new interval
            m_intervals.insert(it, {val, val});
        }
    }
    
    vector<vector<int>> getIntervals() {
        return m_intervals;
    }
private:
    vector<vector<int>> m_intervals;
};

void print_intervals(vector<vector<int>> vv) {
    cout << "[" << endl;
    for (auto & v : vv) {
        cout << "[";
        for (auto & e : v) {
            cout << e << ", ";
        }
        cout << "] " << endl;
    }
    cout << "]" << endl;
}

int main() {
    SummaryRanges ranges;
    ranges.addNum(6);
    print_intervals(ranges.getIntervals());
    ranges.addNum(6);
    print_intervals(ranges.getIntervals());
    ranges.addNum(0);
    print_intervals(ranges.getIntervals());
    ranges.addNum(4);
    print_intervals(ranges.getIntervals());
    ranges.addNum(8);
    print_intervals(ranges.getIntervals());
    ranges.addNum(7);
    print_intervals(ranges.getIntervals());
    ranges.addNum(6);
    print_intervals(ranges.getIntervals());
    ranges.addNum(4);
    print_intervals(ranges.getIntervals());
    ranges.addNum(7);
    print_intervals(ranges.getIntervals());
    ranges.addNum(5);
    print_intervals(ranges.getIntervals());
    return 0;

}