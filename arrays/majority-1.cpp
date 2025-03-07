// 229. Majority Element II
//     Solved
//         Medium
//             Topics
//                 Companies
//                     Hint
//                         Given an integer array of size n,
//     find all elements that appear more than ⌊ n / 3 ⌋ times.

//                                                   Example 1 :

//     Input : nums = [ 3, 2, 3 ] Output : [3] Example 2 :

//     Input : nums = [1] Output : [1] Example 3 :

//     Input : nums = [ 1, 2 ] Output : [ 1, 2 ]


// TC - O(n)/ SC - O(n)+ O(n)
// class Solution
// {
// public:
//     vector<int> majorityElement(vector<int> &nums)
//     {
//         vector<int> ans;
//         int n = nums.size();
//         unordered_map<int, int> mp;

//         for (int i = 0; i < n; i++)
//         {
//             mp[nums[i]]++;
//         }

//         for (auto it : mp)
//         {
//             if (it.second > n / 3)
//             {
//                 ans.push_back(it.first);
//             }
//         }

//         return ans;
//     }
// };

// TC -O(n) / Sc - O(1) as we are not using any extra spaces 
// class Solution {
//     public:
//         vector<int> majorityElement(vector<int>& nums) {
//             // vector<int> ans;
//             // int n = nums.size();
//             // unordered_map<int, int> mp;
    
//             // for (int i = 0; i < n; i++) {
//             //     mp[nums[i]]++;
//             // }
    
//             // for(auto it: mp){
//             //   if(it.second > n/3){
//             //     ans.push_back(it.first);
//             //   }
//             // }
    
//             // return ans;
//             int n = nums.size();
//             int num1 = -1, num2 = -1, cnt1 = 0, cnt2 = 0;
    
//             for (int num : nums) {
//                 if (num == num1) {
//                     cnt1++;
//                 } else if (num == num2) {
//                     cnt2++;
//                 } else if (cnt1 == 0) {
//                     num1 = num;
//                     cnt1 = 1;
//                 } else if (cnt2 == 0) {
//                     num2 = num;
//                     cnt2 = 1;
//                 } else {
//                     cnt1--;
//                     cnt2--;
//                 }
//             }
    
//             cnt1 = cnt2 = 0;
//             for (int num : nums) {
//                 if (num == num1)
//                     cnt1++;
//                 else if (num == num2)
//                     cnt2++;
//             }
    
//             vector<int> res;
//             if (cnt1 > n / 3)
//                 res.push_back(num1);
//             if (cnt2 > n / 3)
//                 res.push_back(num2);
    
//             return res;
//         }
//     };