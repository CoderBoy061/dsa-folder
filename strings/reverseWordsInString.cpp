#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
// TC- O(N);
// SC - O(1);
string reverseWords(string s)
{

    // reverse the entire string

    reverse(s.begin(), s.end());
    string ans = "";

    // calculate and store every individual string
    for (int i = 0; i < s.length(); i++)
    {
        string word = "";
        while (i < s.length() && s[i] != ' ')
        {
            word += s[i];
            i++;
        }

        // after getting the word simply reverse that word
        reverse(word.begin(), word.end());

        // now add the reversed words insinde ans string

        if (word.length() > 0)
        {
            ans += " " + word;
        }
    }
    return ans.substr(1); // removging ythe first soace
}

int main()
{
    string s = "the sky is blue";
    cout << reverseWords(s) << endl;

    return 0;
}