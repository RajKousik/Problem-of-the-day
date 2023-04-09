class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges)
    {
        int n = colors.size();
        
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        
        for(auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        
        vector<vector<int>> count(n, vector<int>(26));
        
        queue<int> q;
        for(int i=0; i<n; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        
        int ans = 0;
        int nodesVisited = 0;
        
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            
            
            ans = max(ans, ++count[node][colors[node] - 'a']);
            nodesVisited++;
            
            for(auto &neighbor : adj[node])
            {
                
                for(int i=0; i<26; i++)
                {
                    
                    count[neighbor][i] = max(count[neighbor][i], count[node][i]);
                
                }
                
                indegree[neighbor]--;

                if(indegree[neighbor] == 0)
                {
                    q.push(neighbor);
                }
                
                
            }
            
        }
        
        return nodesVisited < n ? -1 : ans;
        
    }
};