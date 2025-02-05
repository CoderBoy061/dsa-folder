
#include<iostream>
#include<stack>
using namespace std;

class MinStack {
private:
    stack<int> mainStack;
    stack<int> minStack;

public:
    MinStack() {}
    void push(int val) {

        // first insert the element into main stack
        mainStack.push(val);

        // now check if the minStack is empty or if the val is <=
        // minDStack.top()

        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    void pop() {
        // check if the minStack.top is eqiual to mainStack.top()
        if (mainStack.top() == minStack.top()) {
            minStack.pop();
        }
        mainStack.pop();
    }

    int top() { return mainStack.top(); }

    int getMin() { return minStack.top(); }
};
// The solution uses two stacks efficiently:
//         1. Push, pop, top, and getMin are all 𝑂(1) O(1).
//         2.The space complexity is 𝑂(𝑛)O(n), 



// Why is Space Complexity O(n) and not O(2n)?

// The minStack does not always duplicate all elements from mainStack. Instead, it only keeps track of the minimum values. Let’s analyze this further:

// Worst Case Scenario:

// In the worst-case scenario, where all elements are pushed in strictly decreasing order, both stacks (‘mainStack’ and ‘minStack’) will contain all n elements because:

// Every new element will be smaller than the current minimum.

// Thus, every element will be pushed to both mainStack and minStack.

// This results in a total space usage of 2n (i.e., n elements in mainStack and n elements in minStack).

// Big-O Notation:

// In Big-O notation, we focus on asymptotic growth and ignore constant factors. Although th


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

// How This Works
// Push:

// If the stack is empty or the pushed value is smaller than the current minimum, add it to minStack with a count of 1.
// If the value equals the current minimum, increment the count of the minimum in minStack.
// Pop:

// When popping, if the popped element is the current minimum:
// Decrement the count in minStack.
// Remove the top of minStack if the count becomes zero.
// Space Optimization:

// In case of duplicates, minStack will store only unique minimum values and their counts, reducing redundant storage.