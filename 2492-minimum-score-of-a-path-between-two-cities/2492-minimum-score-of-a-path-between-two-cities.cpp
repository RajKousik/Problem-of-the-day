class Solution {
    
    int bfs(vector<vector<pair<int, int>>> &adj, int n)
    {
        
        //normal BFS function, pushing the 1
        // so that, 1's component will be traversed by the BFS
        //find the minimum edge in this component
        //return the minimum edge
        
        queue<int> q;
        q.push(1);
        
        vector<int> vis(n+1, false);
        vis[1] = true;
        
        int ans = INT_MAX;
        
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            
            for(auto it : adj[node])
            {
                ans = min(ans, it.second);
                if(!vis[it.first])
                {
                    vis[it.first] = true;
                    q.push(it.first);
                }
            }
            
        }
        
        return ans;
        
    }
    
    
    void dfs(int node,vector<vector<pair<int, int>>> &adj, int n, int &ans, vector<int> &vis)
    {
        vis[node] = true;
        
        for(auto it : adj[node])
        {
            ans = min(ans, it.second);
            if(!vis[it.first])
            {
                dfs(it.first, adj, n, ans, vis);
            }
        }
        
    }
    
public:
    int minScore(int n, vector<vector<int>>& roads)
    {
        //There are multiple components
        //But what sure is, 1 and n are in the same component
        //we have to find shortest edge in the path 1->n, 
        // we can traverse as many edges as possible
        
        //so the problem is to find the smallest edge in the given graph
        //more precisely, the problem is to find the smallest edge in the component which has 1 and n
        
        //as there is a chance of multiple components, find the component which has 1 (or) n in it, and find the shortest edge in that component ;)
        
        vector<vector<pair<int, int>>> adj(n+1);    //1 based index of roads
        
        for(auto &it : roads)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});      //bi-directional road
        }
        
        // return bfs(adj, n);
        
        vector<int> vis(n+1, false);
        // vis[1] = true;
        int ans = INT_MAX;
        dfs(1, adj, n, ans, vis);
        
        return ans;
    }
};