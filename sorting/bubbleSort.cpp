#include <iostream>
#include <vector>
using namespace std;
// Time Complexity - O(n^2)
void bubbleSort(vector<int> &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
int main()
{

    vector<int> arr = {5, 4, 3, 2, 1};
    int n = arr.size();

    bubbleSort(arr, n);

    // printing the array after sorting
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}