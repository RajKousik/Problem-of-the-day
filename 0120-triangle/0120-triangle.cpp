class Solution {
public:
    
    int solve(int i, int j, int n, vector<vector<int>> &triangle, vector<vector<int>> &dp)
    {
        if(i >= n)
        {
            return 0;
        }
        // if(i == n-1)
        // {
        //     return triangle[n-1][j];
        // }
        
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        
        int down = triangle[i][j] + solve(i+1, j, n, triangle, dp);
        int downRight = triangle[i][j] + solve(i+1, j+1, n, triangle, dp);
        
        return dp[i][j] = min(down, downRight);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return solve(0, 0, n, triangle, dp);
    }
    
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n = triangle.size();
//         vector<vector<int>> dp(n, vector<int> (n, 0));
        
//         for(int i=0; i<n; i++)
//         {
//             dp[n-1][i] = triangle[n-1][i];
//         }
//         for(int i=n-2; i>=0; i--)
//         {
//             for(int j=i; j>=0; j--)
//             {
//                 int down = triangle[i][j] + dp[i+1][j];
//                 int downRight = triangle[i][j] + dp[i+1][j+1];
//                 dp[i][j] = min(down, downRight);
//             }
//         }
//         return dp[0][0];
//     }
    
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n = triangle.size();
        
//         vector<int> next(n,0);
        
//         for(int i=0; i<n; i++)
//         {
//             next[i] = triangle[n-1][i];
//         }
//         for(int i=n-2; i>=0; i--)
//         {
//             vector<int> curr(n,0);
//             for(int j=i; j>=0; j--)
//             {
//                 int down = triangle[i][j] + next[j];
//                 int downRight = triangle[i][j] + next[j+1];
//                 curr[j] = min(down, downRight);
//             }
//             next = curr;
//         }
//         return next[0];
//     }
};