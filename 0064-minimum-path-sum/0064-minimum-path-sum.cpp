class Solution {
public:
    
    int recurse(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp)
    {
        
        if(i >= grid.size() or j >= grid[0].size())
        {
            return INT_MAX; 
        }
        
        if(i == grid.size()-1 and j == grid[0].size()-1)
        {
            return grid[i][j];
        }
        
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        
        int right = recurse(grid, i, j+1, dp);
        
        int down = recurse(grid, i+1, j, dp);
        
        return dp[i][j] = grid[i][j] + min(right, down);
        
        
    }
    
    int minPathSum(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        return recurse(grid, 0, 0, dp);
    }
};