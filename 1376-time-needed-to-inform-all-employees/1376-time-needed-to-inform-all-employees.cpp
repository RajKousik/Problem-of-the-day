class Solution 
{
private:
    
    void dfsHelperFunction(int node, vector<int> adj[], vector<int> &informTime, int currentTime, int &maxi)
    {
        
        maxi = max(maxi, currentTime);
        
        for(auto it : adj[node])
        {
            dfsHelperFunction(it, adj, informTime, currentTime + informTime[node], maxi);
        }
        
    }
    
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        vector<int> adj[n];
        
        for(int i=0; i<n; i++)
        {
            if(manager[i] != -1)
                adj[manager[i]].push_back(i);
        }
        
        int maxi = INT_MIN;
        
        dfsHelperFunction(headID, adj, informTime, 0, maxi);
        
        return maxi;
        
    }
};