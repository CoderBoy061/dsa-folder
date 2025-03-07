// Problem statement
// You are given an integer array 'arr' of size 'N' and an integer 'K'.

// Your task is to find the total number of subarrays of the given array whose sum of elements is equal to k.

// A subarray is defined as a contiguous block of elements in the array.

// Example:
// Input: ‘N’ = 4, ‘arr’ = [3, 1, 2, 4], 'K' = 6

// Output: 2

// Explanation: The subarrays that sum up to '6' are: [3, 1, 2], and [2, 4].

/*

    Brute Force = we can use two for loops or with i and j;
    if we fix the i and increame the j everytime untill j<n, we can get the subarray, simply add the subarray and check if ti is qual to k, then simply increment the count
    TC-O(n^2), SC-O(1)

*/

// int subarrayCount(int arr, int k)
// {
//     int count = 0;
//     for (int i = 0; i < n; i++)
//     {
//         int sum = 0;

//         for (int j = i; j < n; j++)
//         {
//             sum += arr[j];
//         }
//         if (sum == k)
//             count++;
//     }
//     return count;
// }


/*

    Optimal Solution - we can use the prefix sum concept.
    1. traverse the entire array, store the current sum, and check the removal part the simpy preSum-k
    2. increment the count ans tore that inide the hashmap
    3. and then return the count

    TC - O(n * logN) SC-O(N)
*/

// int findAllSubarraysWithGivenSum(vector<int> &arr, int k) {
//   // Write Your Code Here
//   map<int, int> mp;
//   int preSum = 0;
//   int count = 0;
//   mp[0] = 1;
//   for (int i = 0; i < arr.size(); i++) {
//     preSum += arr[i];
//     // remove the prefix sume to get the value of k and tore that inside the map
//     // and it count
//     int remove = preSum - k;
//     count += mp[remove];
//     mp[preSum] += 1;
//   }
//   return count;
// }