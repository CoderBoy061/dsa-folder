//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
// TC - O(4n^2)
// SC - O(n*m)
class Solution {
  public:
    bool isSafe(int newX, int newY,vector<vector<bool>> &vis,vector<vector<int>> &arr,int n){
        if(( newX >=0 && newX < n ) &&
            (newY >=0 && newY < n) &&
            vis[newX][newY] !=1 &&
            arr[newX][newY] == 1
        ) {
            return true;
        }
        else
            return false;
    }
    void solve(int x, int y,vector<vector<int>> &arr, int n,
               vector<string>&ans, vector<vector<bool>> &vis, string path ){
        if(x==n-1 && y==n-1){
            ans.push_back(path);
            return;
        }
        
        // move the Rat
        vis[x][y] =1;
        //Down
        if(isSafe(x+1,y,vis,arr,n)){
            solve(x+1,y,arr,n,ans,vis,path+"D");
        }
        //left
        if(isSafe(x,y-1,vis,arr,n)){
            solve(x,y-1,arr,n,ans,vis,path+"L");
        }
        // right
        if(isSafe(x,y+1,vis,arr,n)){
            solve(x,y+1,arr,n,ans,vis,path+"R");
        }
        // Up
        if(isSafe(x-1,y,vis,arr,n)){
            solve(x-1,y,arr,n,ans,vis,path+"U");
        }
        // marking the visisted into 0 while goign back
        vis[x][y] = 0;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
      // make the required data structures
      int n = mat.size();
      vector<string>ans;
      vector<vector<bool>> visited(n,vector<bool>(n,0));
      string path = "";
      // check for base case, if the starting index of the matrix is == 0, 
      if(mat[0][0]==0) return ans;
      
      // now solve the main solve function to perform recursion
      
      solve(0,0, mat,n,ans,visited,path);
      return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends