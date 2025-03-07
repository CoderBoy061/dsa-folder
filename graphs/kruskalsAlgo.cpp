/*
    Kruskal's algortihm is used to find out the miniup spannig tree using disjoint method

    Disjoint -  its has two method - make union, find parent or find rank

    Algorithm : 

                1. Find the ultimate parent 
                2. Find Rank of Ultimate Prent 
                3. Connect smaller rank to the larger rank to avoid height increasing
    For Kruskal's algo we can use path compression 
                like if the nodes is belong to the same parent then just simply remove the middle edges and then connect with the 
                main or ultimate parent
                1 -> 4-> 5->7
                here the ultimate parent of the 7 is 1, if anyone asks me to find the parent to 7 , then eventuallky I have to traverse from 7 - to 5 , then  4 and then finally 1
                instead of sdoing that, we can simply connect 7 to 1, to avoid unnecessary time complexity 

*/

// #include<algorithm>
// #include <vector>

// // sorting the vector based on the weight 
// bool cmp(vector<int> &a , vector<int> &b){
//   return a[2] < b[2];
// };

// void makeInitialSetup(vector<int> &parent , vector<int> &rank , int n){
//   for( int i=0;i<n;i++){
//     parent[i] = i; // initially making the parent its node itself
//     rank[i] =0 ; // setting the rank 0 initially
//   }
// };

// int findUltimateParent(vector<int> &parent, int node) {

//   // base case, if the node == parent, means already reches the ultimate parent 

//   if(parent[node] == node) return  node;

//   // here dsoing the path compression as well
//   parent[node] = findUltimateParent(parent, parent[node]);
// };

// void makeUnion( int u , int v, vector<int> &parent, vector<int> &rank){

//   // find the parent for both edges
//    u = findUltimateParent(parent, u);
//    v = findUltimateParent(parent, v);

//    // check and compare the ranks

//   // as per the logic, we have to add the small tree to the larger tree to avoid height increasing 
//    if(rank[u] < rank[v]){
//      parent[u] = v; 
//    }

//    else if(rank[v] < rank[u]){
//      parent[v] =  u;
//    }

//   // means both ranks are equal or 0 , so the edge can be formed between both of them
//    else{
//      parent[v] = u;
//      rank[u] = v;
//    }
// }


// int minimumSpanningTree(vector<vector<int>>& edges, int n)
// {

//   sort(edges.begin(), edges.end(),cmp);
//   vector<int> parent(n); // for 0 based indexing
//   vector<int> rank(n); // for 0 based indexing 
//   makeInitialSetup(parent, rank, n);

//   // intial weights would be 0
//   int wInit = 0;

//   // traverse through the edges 
//   for(int i=0;i<edges.size();i++){
//     int u = findUltimateParent(parent, edges[i][0]);
//     int v = findUltimateParent(parent, edges[i][1]);
//     int weight = edges[i][2];

//      if(u != v){
//        wInit +=weight;
//        makeUnion( u,  v,  parent,  rank);
//      }
//   }
//   return wInit;
// }