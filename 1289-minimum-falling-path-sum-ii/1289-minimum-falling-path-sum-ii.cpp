class Solution {
    
    // int dfs(int row, int col, vector<vector<int>>& grid, int n, vector<vector<int>> dp)
//     {
//         if(col >= n or col < 0)
//         {
//             return 1e6;
//         }
//         if(row == n-1)
//         {
//             return grid[row][col];
//         }
        
//         if(dp[row][col] != -1)
//         {
//             return dp[row][col];
//         }
        
//         int ans = 1e6;
//         for(int nextCol = 0; nextCol < n; nextCol++)
//         {
//             if(col != nextCol)
//             {
//                 ans = min(ans, dfs(row+1, nextCol, grid, n, dp));
//             }
//         }
        
//         return dp[row][col]  = grid[row][col] + ans;
        
//     }
    
public:
//     int minFallingPathSum(vector<vector<int>>& grid) {
        
//         int n = grid.size();
        
//         int ans = INT_MAX;
//         vector<vector<int>> dp(n, vector<int>(n, -1));
//         for(int col=0; col<n; col++)
//         {
//             ans = min(ans, dfs(0, col, grid, n, dp));
//         }
//         return ans;
//     }
    
        int minFallingPathSum(vector<vector<int>>& grid) {
        
            int n = grid.size();

            int ans = INT_MAX;
            
            vector<vector<int>> dp(n, vector<int>(n, 0));
            for(int col=0; col<n; col++)
            {
                  dp[n-1][col] = grid[n-1][col];
            }
            
            for(int row=n-2; row>=0; row--)
            {
                for(int col=n-1; col>=0; col--)
                {
                    int ans = 1e6;
                    for(int nextCol = 0; nextCol < n; nextCol++)
                    {
                        if(col != nextCol)
                        {
                            ans = min(ans, dp[row+1][nextCol]);
                        }
                    }
                    dp[row][col] = grid[row][col] + ans;
                }
            }
            
            for(int col=0; col<n; col++)
            {
                  ans = min(ans, dp[0][col]);
            }
            
            return ans;
            
        }
    
};