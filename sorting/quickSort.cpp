#include <iostream>
#include <vector>
using namespace std;

// here we will pick the pivot, and return the index of that pivot
int partition(vector<int> &arr, int st, int end)
{
    int pivot = arr[end]; // taking the last element as pivot
    int idx = st - 1;     // this will create the place while swaping the variables
    for (int j = st; j < end; j++)
    {
        if (arr[j] <= pivot)
        {
            idx++; // place the index positon to a valid position
            swap(arr[j], arr[idx]);
        }
    }
    // now againg put the idx variable into a valid postion
    idx++;
    swap(arr[end], arr[idx]);

    return idx; // returning the idx postion
}
void mergeSort(vector<int> &arr, int st, int end)
{
    if (st < end)
    {

        int pivotIdx = partition(arr, st, end);
        mergeSort(arr, st, pivotIdx-1);      // sorting the left part
        mergeSort(arr, pivotIdx + 1, end); // sorting the right part
    }
}
int main()
{

    vector<int> arr = {5, 2, 6, 4, 1, 3};
    int st = 0, end = arr.size()-1;

    mergeSort(arr, st, end);

    for (int i = 0; i < end; i++)
    {
        cout << arr[i];
    }
    cout << endl;
    return 0;
}