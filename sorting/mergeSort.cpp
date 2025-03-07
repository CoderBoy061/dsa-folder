#include <iostream>
#include <vector>

using namespace std;

// TC - O(N)

void mergeArray(vector<int> &nums, int start, int mid, int end)
{
    vector<int> temp;
    int i = start;
    int j = mid + 1;
    while (i <= mid && j <= end)
    {
        if (nums[i] <= nums[j])
        {
            temp.push_back(nums[i]);
            i++;
        }
        else
        {
            temp.push_back(nums[j]);
            j++;
        }
    }

    // Check for remaining elements in the first half
    while (i <= mid)
    {
        temp.push_back(nums[i]);
        i++;
    }
    // Check for remaining elements in the second half
    while (j <= end)
    {
        temp.push_back(nums[j]);
        j++;
    }

    // Copy the temp elements back into the original array
    for (int idx = 0; idx < temp.size(); idx++)
    {
        nums[start + idx] = temp[idx];
    }
}

void mergeSort(vector<int> &nums, int start, int end)
{
    if (start < end) // Use `if` instead of `while` for recursion
    {
        int mid = start + (end - start) / 2; // Calculate the middle index

        mergeSort(nums, start, mid);   // Sort the left part
        mergeSort(nums, mid + 1, end); // Sort the right part

        mergeArray(nums, start, mid, end); // Merge the sorted halves
    }
}

int main()
{
    vector<int> nums = {2, 5, 8, 7, 22, 36, 41, 88, 7, 1};
    int start = 0, end = nums.size() - 1;

    mergeSort(nums, start, end);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
