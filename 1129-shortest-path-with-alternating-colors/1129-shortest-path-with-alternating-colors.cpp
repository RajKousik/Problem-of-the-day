class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        vector<vector<pair<int, int>>> adj(n);
        
        for(auto &it : redEdges)
        {
            adj[it[0]].push_back({it[1], 0});
        }
        
        for(auto &it :blueEdges)
        {
            adj[it[0]].push_back({it[1], 1});
        }
        
        vector<vector<bool>> vis(n, vector<bool>(2, false));
        queue<vector<int>> q;
        vector<int> ans(n, -1);
        
        vis[0][0] = vis[0][1] = true;
        q.push({0, 0, -1});
        ans[0] = 0;
        
        while(!q.empty())
        {
            
            auto container = q.front();
            q.pop();
            
            int node = container[0];
            int steps = container[1];
            int prevColor = container[2];
            
            for(auto it : adj[node])
            {
                int neigh = it.first;
                int color = it.second;
                
                if(!vis[neigh][color] and color != prevColor)
                {
                    vis[neigh][color] = true;
                    q.push({neigh, steps + 1, color});
                    
                    if(ans[neigh] == -1)
                    {
                        ans[neigh] = 1 + steps;
                    }
                }
                
            }
            
        }
        
        return ans;
        
        
        
    }
};