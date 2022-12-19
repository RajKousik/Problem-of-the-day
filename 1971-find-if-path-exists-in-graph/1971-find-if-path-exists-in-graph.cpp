class Solution {
public:
    
    bool dfs(vector<int> adj[], int node, int dest, vector<int> &vis)
    {
        
        if(node == dest) return true;

        
        if(!vis[node])
        {
            vis[node] = true;
            for(auto it : adj[node])
            {
                if(dfs(adj, it, dest, vis))
                {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<int> adj[n];
        
        for(auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n, false);
        return dfs(adj, source, destination, vis);

        return -1;
        
    }
};