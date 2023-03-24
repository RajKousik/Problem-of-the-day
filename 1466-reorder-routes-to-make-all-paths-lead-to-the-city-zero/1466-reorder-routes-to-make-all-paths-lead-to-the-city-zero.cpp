class Solution {
    
//     void dfs(int node, vector<pair<int, bool>> adj[], int n, int &count, vector<bool> &vis)
//     {
        
//         vis[node] = true;
//         for(auto it : adj[node])
//         {
//             if(!vis[it.first])
//             {
//                 if(it.second == true)
//                 {
//                     count++;
//                 }

//                 dfs(it.first, adj, n, count, vis);
//             }
//         }
        
//     }
    
        int bfs(int node, vector<pair<int, bool>> adj[], int n)
        {
            queue<int> q;
            q.push(node);
            
            vector<bool> vis(n, false);
            vis[node] = true;
            
            int count = 0;
            
            while(!q.empty())
            {
                auto city = q.front();
                q.pop();
                
                for(auto it : adj[city])
                {
                    if(!vis[it.first])
                    {
                        vis[it.first] = true;
                        count += it.second;
                        q.push(it.first);
                    }
                    
                }
                
            }
            return count;
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
        
        
        // vector<bool> vis(n, false);
        
        // int count = 0;
        // dfs(0, adj, n, count, vis);
        // return count;
        
        return bfs(0, adj, n);
        
        
    }
};