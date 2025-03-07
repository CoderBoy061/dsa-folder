#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
int findDuplicate(vector<int> &nums)
{
    unordered_set<int> s;
    for (int val : nums)
    {
        if (s.find(val) != s.end())
        {
            return val;
        }
        s.insert(val);
    }
    return -1;
}
int main()
{
    vector<int> nums = {1, 2, 3, 5, 6, 7, 6, 9};

    cout << findDuplicate(nums) << endl;
}