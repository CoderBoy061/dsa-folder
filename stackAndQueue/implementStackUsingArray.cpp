#include <iostream>

using namespace std;

class Stack
{

public:
    int top = -1;
    int st[100]; // assuming  that we have to implement 10 sizes queue

    void push(int val)
    {
        // before doing anything check if the space is availabe
        if (top >= 10)
        {
            cout << "No Place" << endl;
        }
        // first increament the top
        top = top + 1;
        st[top] = val;
    }

    // get the top

    int getTop()
    {
        // check if the stack is empty or not?
        if (top == -1)
            return -1;

        return st[top];
    }
    void pop()
    {

        if (top == -1)
        {
            cout << "stack is emplyt" << endl;
        }

        top = top - 1;
    }

    int size()
    {
        if (top == -1)
        {
            return -1;
        }
        return top + 1;
    }
};

int main()
{
    Stack st;
    st.push(5);
    cout << st.getTop() << endl;

    return 0;
}