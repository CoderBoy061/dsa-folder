#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>

using namespace std;

/*
    approach1 =>
    1. We can use sorting algo, like if we sort the array and can return the arr[k-1] value
    TC for this approch will be O(nlogn)

     approach2 => We can use max-heap to solve this question
*/


int main()
{
    vector<int> nums = {7, 10, 4, 3, 20, 15};
    priority_queue<int>pq;
    int k =4;
    // first store the 1 toh kth element into the PQ
    for(int i=0;i<nums.size();i++){
        pq.push(nums[i]);
    }

    // now traverse the k-1 to n and check if any elelmtn is smaller than pq.top, replace that with the top element

    for(int i=k; i<nums.size();i++){
        if(nums[i] < pq.top()){
            pq.pop();
            pq.push(nums[i]);
        }
    }
    cout  << pq.top() << endl;
    // sort(nums.begin(), nums.end());
    // int k = 4;

    // cout << nums[k - 1] << endl;

    return 0;
}