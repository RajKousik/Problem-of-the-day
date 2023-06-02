class Solution 
{
    
private:
    
    void dfs(int node, vector<int> adj[], vector<bool> &vis, int &count)
    {
        count++;
        vis[node] = true;
        for(auto it : adj[node])
        {
            if(vis[it] == false)
            {
                dfs(it, adj, vis, count);
            }
        }
        
    }
        
    
public:
    int maximumDetonation(vector<vector<int>>& bombs) 
    {
        /*
        make it as a directed graph, a -> b , bomb a can detonate bomb b
        
        simply run the dfs and find the maximum count;
        
        to find whether a bomb can detonate another bomb we can use
        euclidean distance 
        
        if radius of A >= euclidean distance of A and B 
        then bomb A can detonate bomb B
        
        radius >= sqrt( (x2 - x1)^2 + (y2 - y1)^2 )
        radius^2 >= (x2 - x1)^2 + (y2 - y1)^2
        */
        
        int n = bombs.size();
        vector<int> adj[n];
        
        for(int i=0; i<n; i++)
        {
            
            long long xi = bombs[i][0];
            long long yi = bombs[i][1];
            long long ri = bombs[i][2];
            
            for(int j=0; j<n; j++)
            {
                if(i == j)
                {
                    continue;    
                }
                
                long long xj = bombs[j][0];
                long long yj = bombs[j][1];
                
                long long euclideanDist = ((xj - xi) * (xj - xi)) + ((yj - yi) * (yj - yi));
                
                if(ri* ri >= euclideanDist)
                {
                    adj[i].push_back(j);
                }
                
            }
        }
        
        int maxi = 1;
        
        for(int i=0; i<n; i++)
        {
            cout<<i<<" -> ";
            for(auto it : adj[i])
            {
                cout<<it<<" ";
            }
            cout<<endl;
        }
        
        
        for(int i=0; i<n; i++)
        {
                vector<bool> vis(n, false);
                int count = 0;
                dfs(i, adj, vis, count);
                // cout<<count<<endl;
                maxi = max(maxi, count);
        }
        
        return maxi;
        
    }
};