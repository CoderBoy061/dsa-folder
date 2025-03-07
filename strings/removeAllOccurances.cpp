#include <iostream>
#include <string.h>
using namespace std;

int main()
{

    string s = "debabrataabcghabcdgabc";
    string part = "abc"; // which we have to remove from the string

    while(s.length() > 0 && s.find(part) < s.length()){
        s.erase(s.find(part), part.length());
    }

    cout << s << endl;

    

    return 0;
}