class Solution 
{
    
private:
    void dfs(int node, vector<bool> &vis, vector<int> adj[])
    {
        vis[node] = true;
        
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                dfs(it, vis, adj);
            }
        }
        
    }
    
public:
    int makeConnected(int n, vector<vector<int>>& connections)
    {
        
        int edges = connections.size();
        
        if(edges < n-1)
        {
            return -1;
        }
        
        vector<int> adj[n];
        
        for(auto it : connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<bool> vis(n, false);
        
        int count = 0;
        
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                dfs(i, vis, adj);
                count++;
            }
        }
        
        return count - 1;
        
    }
};