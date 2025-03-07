

// vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
// 	// Write your code here
// 	vector<vector<int>> adj(n+1);

// 	// preparing the adj list
// 	for(int i=0;i<edges.size();i++){
// 		int u = edges[i].first;
// 		int v = edges[i].second;
// 		adj[u].push_back(v);
// 		adj[v].push_back(u);
// 	}

// 	vector<int>visited(n+1,false);
// 	queue<int>q;
// 	// setting the first node and its parent node which is -1
// 	vector<int> parent(n + 1, -1);
// 	visited[s]= true;
// 	q.push(s);
// 	vector<int>ans;

// 	// traverse 
// 	while(!q.empty()){
// 		int front = q.front();
// 		q.pop();
// 		for(auto i: adj[front]){
// 			if(!visited[i]){
// 				visited[i] = true;
// 				q.push(i);
// 				parent[i]= front;
// 			}

// 		}
// 	}	

// 	  // If target `t` is not reachable
//     if (!visited[t]) {
//         return {};
//     }
// 	int currentNode = t;
// 	ans.push_back(t);

// 	while(currentNode != s){
// 		currentNode = parent[currentNode];
// 		ans.push_back(currentNode);
// 	};

// 	reverse(ans.begin(), ans.end());
// 	return  ans;
// }
