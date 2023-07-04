class Solution {
    
    int dfs(int row, int col, vector<vector<int>>& mat, int n, vector<vector<int>> &dp)
    {
        if(row == n)
        {
            return 0;
        }
        
        if(dp[row][col] != -1)
        {
            return dp[row][col];
        }
        
        int down = dfs(row+1, col, mat, n, dp);
        int downRight = dfs(row + 1, col + 1, mat, n, dp);
        
        return dp[row][col] = mat[row][col] + min(down, downRight);
    }
    
public:
    int minimumTotal(vector<vector<int>>& mat) {
        
        // int minSum = INT_MAX;
        int n = mat.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return dfs(0, 0, mat, n, dp);
        
    }
};