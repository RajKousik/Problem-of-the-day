class Solution {
    
    void dfs(int node, vector<pair<int, bool>> adj[], int n, int &count, vector<bool> &vis)
    {
        
        vis[node] = true;
        for(auto it : adj[node])
        {
            if(!vis[it.first])
            {
                if(it.second == true)
                {
                    count++;
                }

                dfs(it.first, adj, n, count, vis);
            }
        }
        
    }
    
public:
    int minReorder(int n, vector<vector<int>>& connections) 
    {
        
        vector<pair<int, bool>> adj[n];
        
        for(auto it : connections)
        {
            adj[it[0]].push_back({it[1], true});        //true represents original edge
            adj[it[1]].push_back({it[0], false});       ////false represents extra edge for traversing
        }
        
        vector<bool> vis(n, false);
        
        int count = 0;
        dfs(0, adj, n, count, vis);
        
        return count;
        
    }
};