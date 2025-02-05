/*
Given an array arr[] and an integer k, where arr[i] denotes the number of pages of a book and k denotes total number of students. All the books need to be allocated to k students in contiguous manner, with each student getting at least one book.

The task is to minimize the maximum number of pages allocated to a student. If it is not possible to allocate books to all students, return -1.

Examples:

Input: arr[] = [12, 34, 67, 90], k = 2
Output: 113
Explanation: Books can be distributed in following ways:


[12] and [34, 67, 90] – The maximum pages assigned to a student is  34 + 67 + 90 = 191.
[12, 34] and [67, 90] – The maximum pages assigned to a student is 67 + 90 = 157.
[12, 34, 67] and [90] – The maximum pages assigned to a student is 12 + 34 + 67 = 113.
The third combination has the minimum pages assigned to a student which is 113.


Input: arr[] = [15, 17, 20], k = 5
Output: -1
Explanation: Since there are more students than total books, it’s impossible to allocate a book to each student.


Input: arr[] = [22, 23, 67], k = 1
Output: 112
Explanation: Since there is only 1 student, all books are assigned to that student. So, maximum pages assigned to a student is 22 + 23 + 67 = 112.

*/

/*
    Brute Force : We can use linear serach, to traverse the enitre array to calculate the minimum, or the maximum pages than can be allocated to
    a student

    1. First we can calculate the minimum pages that can be allocated, which is the max of the array or the max number of pages that can be allocated to a student
    2. Second we can calculate the maximum pages that can be allocate, whihc is the sum of all the pages, in worst case scenario, there can be only 1 student and if we need to allocate  [15, 17, 20] pages, there will be only one way and that is all the pages will go to the student 1. it is the sum of all the pages
    3. So, the range would be from minimu to maximum, and then we can check for the maximum pages can be allowed to allocate for a particular student
*/


// Time Complexity - O(n*(Sum(arr) – MAX))
// Space Complexity - O(1)
#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

int findMinimum(vector<int> &arr, int n)
{
    int maximum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maximum = max(maximum, arr[i]);
    }
    return maximum;
}

int findSum(vector<int> &arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int checkValidAllocation(vector<int> &arr, int maxPageAllowed)
{
    int student = 1, pagesOnStudent = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        // if the sum is less than equal to the max allowed pages, the add them, otheriwse simple add a new student and give him the current page
        if (pagesOnStudent + arr[i] <= maxPageAllowed)
        {
            pagesOnStudent += arr[i];
        }
        else
        {
            student++;
            pagesOnStudent = arr[i];
        }
    }
    return student;
}

int findPages(vector<int> &arr, int k)
{
    int n = arr.size();
    // we can check if the studens is greater than the number of pages, then there is not possible way to allocate pages,bceuase we have to allocate in contiguos manner

    if (k > n)
        return -1;

    // now find the minimum and maximum possible pages that can be allocated to a particular problem
    int minimumPages = findMinimum(arr, n);
    int maximumPages = findSum(arr, n);

    // Iterating over all possible page limits
    for (int i = minimumPages; i < maximumPages; i++)
    {
        int currentStdent = checkValidAllocation(arr, i);

        if (currentStdent == k)
            return i;
    }
    return -1;
}
int main()
{
    vector<int> arr = {12, 34, 67, 90};
    int k = 5;
    cout << findPages(arr, k);
    return 0;
}