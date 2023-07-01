//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int node, int parent, vector<int> adjList[], vector<bool> &vis)
    {
    	vis[node] = true;
    	
    	for(auto it : adjList[node])
    	{
    		if(!vis[it])
    		{
    			if(dfs(it, node, adjList, vis))
    				return true;
    		}
    		else if(it != parent)
    		{
    			return true;
    		}
    	}
    	return false;
    }
    
    bool isCycle(int V, vector<int> adjList[]) {
        // add your logic here
    	int n = V;
    	vector<bool> vis(n+1, false);
    	for(int i=0; i<n; i++)
    	{
    		if(!vis[i])
    		{
    			if(dfs(i, -1, adjList, vis))
    				return true;
    		}
    	}
    	return false;
    }
    // bool isCycle(int V, vector<int> adj[]) {
    //     // Code here
    // }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends