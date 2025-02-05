#include <iostream>
#include <vector>
using namespace std;

// TC using mergesort - O(nlogn), SC-O(n)- for temp array
int mergeBothPart(vector<int> &arr, int st, int mid, int end)
{

    int i = st, j = mid + 1, inversionCount = 0;
    vector<int> temp;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
            inversionCount += (mid - i + 1);
        }
    }

    // run for individual part
    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }

    for (int idx = 0; idx < temp.size(); idx++)
    {
        arr[idx + st] = temp[idx];
    }

    return inversionCount;
}
int mergeSort(vector<int> &arr, int st, int end)
{
    while (st < end)
    {
        int mid = st + (end - st) / 2;

        // sort the left part
        int leftInversionCount = mergeSort(arr, st, mid);

        // sort the right part
        int rightInversionCount = mergeSort(arr, mid + 1, end);
        // finally merge the both sorted part to a big part

        int finalInversionCount = mergeBothPart(arr, st, mid, end);

        return leftInversionCount + rightInversionCount + finalInversionCount;
    }
    return 0;
}
int main()
{
    vector<int> arr = {6, 3, 5, 2, 7};
    // int inversionCount = mergeSort(arr, 0, arr.size() - 1);
    int inversionCount =0;

    // brute force - O(n^2)
    for(int i=0;i<arr.size();i++){
        for(int j=i+1; j<arr.size();j++){
            if(arr[i] > arr[j]){
                inversionCount++;
            }
        }
    }

    cout << inversionCount << endl;
    return 0;
}