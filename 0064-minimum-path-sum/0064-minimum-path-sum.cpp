class Solution {

private:
    
    int dfs(int i, int j, vector<vector<int>>& grid, int m, int n, vector<vector<int>> &dp)
    {
        if(i >= m or j >= n)
        {
            return INT_MAX;
        }
        if(i == m-1 and j == n-1)
        {
            return grid[i][j];
        }
        
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        
        int right = dfs(i, j+1, grid, m, n, dp);
        int down = dfs(i+1, j, grid, m, n, dp);
        
        return dp[i][j] = grid[i][j] + min(right, down);
    }
    
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return dfs(0, 0, grid, m, n, dp);
    }
};