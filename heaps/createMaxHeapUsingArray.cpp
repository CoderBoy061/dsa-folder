// we can use heapify Algorithm

#include <iostream>
#include <vector>

using namespace std;
// =============================heapify algorithm function==============================
void heapify(vector<int> &nums, int n, int i)
{
    // first get the left ans right element
    int left = 2 * i;
    int right = 2 * i + 1;
    int largest = i;

    // check the left element if it is bigger than the current value
    if (left < n && nums[largest] < nums[left])
    {
        largest = left; // update the largest element with its left data
    }
    // same check in the right side

    if (right < n && nums[largest] < nums[right])
    {
        largest = right; // updating the largest element with the right data
    }
    if (largest != i)
    {
        swap(nums[largest], nums[i]); // swap the largest with the nums[i] element 
        heapify(nums, n, largest); // place the index its correct position
    }
}
// =============================for min-heap===========================
void heapify(vector<int> &nums, int n, int i)
{
    // first get the left ans right element
    int left = 2 * i;
    int right = 2 * i + 1;
    int smallest = i;

    // check the left element if it is bigger than the current value
    if (left < n && nums[smallest] > nums[left])
    {
        smallest = left; // update the largest element with its left data
    }
    // same check in the right side

    if (right < n && nums[smallest] > nums[right])
    {
        smallest = right; // updating the largest element with the right data
    }
    if (smallest != i)
    {
        swap(nums[smallest], nums[i]); // swap the largest with the nums[i] element 
        heapify(nums, n, smallest); // place the index its correct position
    }
}
// =============================heap sort algo====================
void heapSort(vector<int> &nums, int n) {
    int size =n;
    while(size > 1){
        swap(nums[size] , nums[1]);
        size--;

        heapify(nums, size, 1);
    }
}

int main()
{

    vector<int> nums = {-1, 54, 53, 55, 52, 50}; // as we are suing 1 based indexing
    int n = nums.size();

    // as we know we dont have to process the elements that are lying from (n/2+1) to N, because those will be the leaf nodes
    // we just need to process from i to n/2

    for (int i = n / 2; i >= 0; i--)
    {
        heapify(nums, n, i); //
    }

    for(int i=0 ;i<n;i++){
        cout << nums[i] << " ";
    }cout << endl;

    return 0;
}