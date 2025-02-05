#include <iostream>
#include <vector>
using namespace std;

// Time Complexity - O(n^2)
void selectionSort(vector<int> &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int smallestIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[smallestIndex])
            {
                smallestIndex = j;
            }
        }
        swap(arr[i], arr[smallestIndex]);
    }
}
int main()
{

    vector<int> arr = {5, 4, 3, 2, 1};
    int n = arr.size();

    selectionSort(arr, n);

    // printing the array after sorting
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}