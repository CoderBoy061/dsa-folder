/*

Problem statement
There is an integer array ‘A’ of size ‘N’.

A sequence is successive when the adjacent elements of the sequence have a difference of 1.

You must return the length of the longest successive sequence.

Note:

You can reorder the array to form a sequence. 
For example,

Input:
A = [5, 8, 3, 2, 1, 4], N = 6
Output:
5
Explanation: 
The resultant sequence can be 1, 2, 3, 4, 5.    
The length of the sequence is 5.

    Brute Force Approach :- run a for loop and initialize a number with the first number of the array
    2. Chck the entire array if the second number is x+1 or not? means if thex=1, then the next number should be 2
    3. if the x+1 number found just simply update the count
    4. last takle the max from the count and update the longest varibale and return it

    TC - O(n^2)

*/

// bool ls(vector<int>&a, int num){
//     for(int i=0;i<a.size();i++){
//         if(a[i]==num) return true;
//     }
//     return false;

    
// }

// int longestSuccessiveElements(vector<int>&arr) {
//     // Write your code here.

//     int longest=1;
//     int n= arr.size();

//     for(int i=0;i<n;i++){
//         int x = arr[i];
//         int count=1;

//         while(ls(arr,x+1) == true){
//             x= x+1;
//             count=count+1;
//         }
//         longest = max(longest, count);
//     }
//     return longest;
// }


/*

    Better Sol = 
    1. We can sort the array to arrage the data in increasing order
    2. we can take a varibale to count the sequence and start with 0
    3. we can take a longest varibale to store the longest seqiuebnce
    4. we can take a lastSmallest varibale and can inoitiale with int_min
    
    Algp : take a number and check the prevoiys one shold be lesst -1, means if the current ith is 2 then the prevoisu should be always 1,
    if it satisfies the condition, then update the curCont and update the lastSmallest with the current Index

    if(arr[i] == lastSmallest) do nothin, its a repeative number\
    else{
        it is not sequeence number, so just update the currCount with 1 and take the arr[i] as the lastSmallest to riun the same process again and again
    }

    Tc- O(nlog n)

*/

// int longestSuccessiveElements(vector<int>&arr) {
//     // Write your code here.

//     int longest=1;
//     int n= arr.size();
//     int currCount=0;
//     int lastSmallest=INT_MIN;

//     // let's osrt the array

//     sort(arr.begin(), arr.end());

//     for(int i=0;i<n;i++){
//         if(arr[i]-1 == lastSmallest){
//             currCount = currCount+1;
//             lastSmallest=arr[i];
//         }

//         // longest = max(longest,currCount);
//         else if(arr[i]== lastSmallest) continue;

//         else{
//             currCount=1;
//             lastSmallest=arr[i];
//         }
//         longest = max(longest, currCount);

//     }

//     return longest;

// }


/*

        Optimal Solution - can use set and store the elements inside set
        now we can taka a srart whihc will be always it-1, means the prevoius element, so that we can save unnecessary traversal

        Overall TC- O(n)+O(n)=O(n)
        SC- O(n);

        int longestSuccessiveElements(vector<int>&arr) {
    
    int n=arr.size();
    if(n==0)return 0;
    int longest=1;

    unordered_set<int>s;
    // inserting all the elements whihc will store unique
    for(int i=0;i<n;i++){
        s.insert(arr[i]);
    }

    for(auto it:s){
        if(s.find(it-1) == s.end()){
            int cnt=1;
            int x=it;
            while(s.find(x+1) !=s.end()){
                x=x+1;
                cnt=cnt+1;
            }
            longest=max(longest,cnt);
        }
    }
    return longest;

}

*/