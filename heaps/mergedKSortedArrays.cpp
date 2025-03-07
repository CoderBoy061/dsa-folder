//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++

class node{
    public:
        int data;
        int row;
        int col;
        
        node(int data, int row, int col){
            this->data = data;
            this->row = row;
            this->col = col;
        }
};

class compare{
    public:
        bool operator()(node*a, node*b){
            return a->data > b->data;
        }
};
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        // for this code we have to use minHeap
        priority_queue<node*, vector<node*>,compare> minHeap;
        vector<int> ans;
        // pu the ffirsyt element of every single row
        // step 1
        for(int i=0;i<K;i++){
            // creating a node and pushing it to the minHeap
            node* temp = new node(arr[i][0],i, 0 );
            minHeap.push(temp);
        }
        // step 2
        // take out the first element from the heap
        while(!minHeap.empty()){
            node* top = minHeap.top();
            // pushing the data into the ans array
            ans.push_back(top->data);
            minHeap.pop(); // popping the first element
            // now push the next element, before pushing check if it is exists or not
            int i = top->row;
            int j = top->col;
            
            if(j+1 < arr[i].size()){
                node* next = new node(arr[i][j+1], i , j+1);
                minHeap.push(next);
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    
cout << "~" << "\n";
}
	return 0;
}






// } Driver Code Ends