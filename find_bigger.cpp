#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <stack>
using std::stack;
using std::vector;
static const int INT_MAX = 100000000;

vector<int> find_bigger(vector<int> num)
{
    if (num.size() == 0)
        return num;
    vector<int> res(num.size());
    int i = 0;
    stack<int> s;
    while (i < num.size())
    {
        if (s.empty() || num[s.top()] >= num[i])
        {
            s.push(i++);
        }
        else
        {
            res[s.top()] = num[i];
            s.pop();
        }
        while (!s.empty())
        {
            res[s.top()] = INT_MAX;
            s.pop();
        }
    }
}

int main()
{
    vector<int> test_case = {3, 4, 2, 4, 56, 23, 12, 47, 28, 90};
    auto result = ::find_bigger(test_case);
    std::ostream_iterator<int> it(std::cout, "");
    std::copy(result.begin(), result.end(), it);
    return 0;
}