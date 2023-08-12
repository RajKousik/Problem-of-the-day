#include<bits/stdc++.h>
class Solution {
public:
    
    int recurse(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &dp)
    {
        if(i<0 or j<0)
            return 0;
        if(i==0 and j==0 and grid[i][j] != 1)
            return 1;
        if(grid[i][j] == 1)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int up = recurse(i-1, j, grid, dp);
        int left = recurse(i, j-1, grid, dp);
        
        return dp[i][j] = up + left;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        
        vector<vector<int>> dp(n , vector<int> (m, -1));
        
        return recurse(n-1, m-1, obstacleGrid, dp);
    }
    
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int n = obstacleGrid.size();
//         int m = obstacleGrid[0].size();
        
//         vector<vector<int>> dp(n , vector<int> (m, 0));
        
//         for(int i=0; i<n; i++)
//         {
//             for(int j=0; j<m; j++)
//             {
//                 if(i==0 and j==0 and obstacleGrid[i][j] != 1)
//                      dp[i][j] = 1;
                
//                 else if(obstacleGrid[i][j] == 1)
//                     dp[i][j] = 0;
//                 else
//                 {
//                     int up=0, left =0;
//                     if(i>0)
//                         up += dp[i-1][j];
//                     if(j>0)
//                         left += dp[i][j-1];
//                     dp[i][j] = up + left;
//                 }
//             }
            
//         }
        
//         return dp[n-1][m-1];
//     }
    
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int n = obstacleGrid.size();
//         int m = obstacleGrid[0].size();
        
//         vector<int> prev(m, 0);
        
//         for(int i=0; i<n; i++)
//         {
//             vector<int> curr(m, 0);
//             for(int j=0; j<m; j++)
//             {
//                 if(i==0 and j==0 and obstacleGrid[i][j] != 1)
//                      curr[j] = 1;
                
//                 else if(obstacleGrid[i][j] == 1)
//                     curr[j] = 0;
//                 else
//                 {
//                     int up=0, left =0;
//                     if(i>0)
//                         up += prev[j];
//                     if(j>0)
//                         left += curr[j-1];
//                     curr[j] = up + left;
//                 }
//             }
//             prev = curr;
//         }
        
//         return prev[m-1];
//     }
};