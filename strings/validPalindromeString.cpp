#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// this fucntion will check for valid palindrome string
bool isAlpha(char c)
{

    if ((c >='a' && c <= 'z') || (c >= 0 && c <= '9'))
    {
        return true;
    }
    return false;
}
int main()
{

    string s = "madam123";
    // using two pointer approach

    int st = 0, end = s.size() - 1;

    while (st <= end)
    {
        if(!isAlpha(tolower(s[st]))){
            st++;
            continue;
        }
        if(!isAlpha(tolower(s[end]))){
            end--;
            continue;
        }

        if(tolower(s[st]) != tolower(s[end])){
            cout << "Not Valid Palindrome" << endl;
        }
        st++, end--;
    }
    cout << "Valid Palindrome" << endl;

    cout << s << endl;

    return 0;
}