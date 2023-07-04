class Solution {
    
//     int dfs(int row, int col, vector<vector<int>>& matrix, int n, vector<vector<int>> &dp)
//     {
//         if(row >= n or row < 0 or col < 0 or col >= n)
//         {
//             return 1e5;
//         }
        
//         if(row == n-1)
//         {
//             return matrix[row][col];
//         }
        
//         if(dp[row][col] != -1)
//         {
//             return dp[row][col];
//         }
        
//         int down = dfs(row+1, col, matrix, n, dp);
//         int downRight = dfs(row+1, col+1, matrix, n, dp);
//         int downLeft = dfs(row+1, col-1, matrix, n, dp);
        
//         return dp[row][col] = matrix[row][col] + min(down, min(downRight, downLeft));
        
//     }
    
public:
//     int minFallingPathSum(vector<vector<int>>& matrix) {
        
//         int ans = 1e5;
        
//         int n = matrix.size();
        
//         vector<vector<int>> dp(n, vector<int>(n, -1));
        
//         for(int col=0; col<n; col++)
//         {
//             ans = min(ans, dfs(0, col, matrix, n, dp));
//         }
//         return ans;
        
//     }
    
       int minFallingPathSum(vector<vector<int>>& matrix) 
       {
        
           int ans = 1e5;
  
           int n = matrix.size();

           vector<vector<int>> dp(n, vector<int>(n, 0));

           for(int j=0; j<n; j++)
           {
               dp[n-1][j] = matrix[n-1][j];
           }
           
           for(int row=n-2; row>=0; row--)
           {
               for(int col=n-1; col>=0; col--)
               {
                    int down = dp[row+1][col];
                   
                    int downRight = 1e5;
                    if(col+1 < n)
                        downRight = dp[row+1][col+1];
                    int downLeft = 1e5;
                    if(col-1 >= 0)
                        downLeft = dp[row+1][col-1];

                    dp[row][col] = matrix[row][col] + min(down, min(downRight, downLeft));
               }
           }
            
           for(int j=0; j<n; j++)
           {
               ans = min(ans, dp[0][j]);
           }
           
           return ans;
        
        }
    
};