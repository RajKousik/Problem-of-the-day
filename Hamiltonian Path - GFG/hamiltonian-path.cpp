//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    
    bool dfs(int node, int cnt, vector<int> &vis, vector<int> adj[], int n)
    {
        
        vis[node] = 1;
        
        
        if(cnt == n)
        {
            return true;
        }
        
        for(auto it : adj[node])
        {
            if(!vis[it] and dfs(it, cnt+1, vis, adj, n))
            {
                return true;
            }
        }
        
        vis[node] = 0;
        
        return false;
        
    }
    
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        // code here
        vector<int> adj[N+1];
        
        for(auto it : Edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> vis(N+1, 0);
        
        for(int i=1; i<=N; i++)
        {
            if(dfs(i, 1, vis, adj, N))
            {
                return true;
            }
        }
        
        return false;
        
    }
};
 

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}
// } Driver Code Ends