class Solution {
public:
    
    int dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &cost, vector<vector<int>> &dp)
    {
        
        if(i == grid.size() - 1)
        {
            return grid[i][j];
        }
        
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        
        int r = cost.size();
        int c = cost[0].size();
        
        int curr = grid[i][j];
        
        int ans = INT_MAX;
        for(int y = 0; y < c; y++)
        {
            int temp = grid[i][j] + cost[curr][y] + dfs(i+1, y, grid, cost, dp);
            // cout<<temp<<endl;
            ans = min(ans, temp);
        }
        
        return dp[i][j] = ans;
    }
    
    
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        
        int ans = INT_MAX;
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        for(int j=0; j<n; j++)
        {
            int currChar = grid[0][j];
            int val =  dfs(0, j, grid, moveCost, dp);
            // cout<<endl<<endl<<ans<<" "<<val<<endl;
            ans = min(ans, val);
        }
        
        return ans;
        
    }
};