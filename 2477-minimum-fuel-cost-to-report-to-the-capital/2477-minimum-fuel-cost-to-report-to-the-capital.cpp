class Solution {
    long long fuel;
    long long dfs(int node, int parent, vector<vector<int>> &adj, int &seats)
    {
        
        int passengers = 1;
        
        for(auto &neigh : adj[node])
        {
            if(neigh != parent)
            {
                passengers += dfs(neigh, node, adj, seats);
            }
        }
        
        if(node != 0)
        {
            fuel += ceil((double)passengers / seats);
        }
        
        return passengers;
        
    }
    
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        
        fuel=0;
        int n = roads.size() + 1;
        vector<vector<int>> adj(n);
        
        for(auto it : roads)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        dfs(0, -1, adj, seats);
        return fuel;
        
    }
};