#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

// brute force TC - O(n2) SC-O(n) - for unordered_set
// int longestSubstr(string &s)
// {
//     int n = s.length();
//     int maxLen = 0;
//     for (int i = 0; i < n; i++)
//     {
//         // insert the first elemene to the hashMap, so next time we can
//         // check if the next eleemt is equal to the same character
//         // marking thr first element as voisited
//         cout << s[i] << endl;
//         unordered_set<char> st;
//         for (int j = i; j < n; j++)
//         {
//             if (st.find(s[j]) != st.end())
//             {
//                 // means we got a duplicate
//                 break;
//             }

//             maxLen = max(maxLen, j - i + 1);
//             st.insert(s[j]);
//         }
//     }
//     return maxLen;
// }

// optimized solutions

int longestSubStr(string &s)
{
    int n = s.length();
    // if(n==0) return 1;
    if (s.length() == 0)
        return 0;
    if (s.length() == 1)
        return 1;
    unordered_set<char> st;
    int left = 0;
    int right = 0;
    int maxLen = 0;

    for (right = 0; right < n; right++)
    {
        while (st.find(s[right]) != st.end())
        {
            st.erase(s[left]); // remove the left occurance
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
        st.insert(s[right]); // inser the current element
    }
    return maxLen;
}
int main()
{
    string s = "au";
    int ans = longestSubStr(s);
    cout << ans << endl;
}