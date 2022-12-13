class Solution {
public:
    
    int dfs(int i, int j, vector<vector<int>> &matrix, int n, vector<vector<int>> &dp)
    {
        
        if(i<0 or i>=n or j<0 or j>=n)
        {
            return 1e5;     //as max no of n is 100, and max value is 100, so max sum will be 10000. so we to have choose greater than 10^4, so we have taken 10^5.
            //see Constraints
        }
        
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        
        if(i == n-1)
        {
            return matrix[i][j];
        }
        
        int down = dfs(i+1, j, matrix, n, dp);
        
        int downLeft = dfs(i+1, j-1, matrix, n, dp);   
       
        int downRight = dfs(i+1, j+1, matrix, n, dp);   
        
        return dp[i][j] = matrix[i][j] + min(down, min(downLeft, downRight));
        
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        
        int ans = 1e5;
    
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        for(int j=0; j<n; j++)
        {
            ans = min(ans, dfs(0, j, matrix, n, dp));
        }
        
        return ans;
        
    }
};