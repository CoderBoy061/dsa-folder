#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{

    string s = "debabrata";

    // brute force/inbuilt
    // reverse(s.begin(), s.end());

    // using two pointer approach

    int st = 0, end = s.size() - 1;

    while(st<=end){
        swap(s[st],s[end]);
        st++;
        end--;
    }

    cout << s << endl;

    return 0;
}