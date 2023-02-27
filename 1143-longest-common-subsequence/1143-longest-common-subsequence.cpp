class Solution {
// private:
//     int findLengthOfLCS(string x, string y, int m, int n, vector<vector<int>> &dp)
//     {
//         if(m == 0 or n == 0)
//         {
//             return 0;
//         }
        
//         if(dp[m][n] != -1)
//         {
//             return dp[m][n];
//         }

//         if(x[m-1] == y[n-1])
//         {
//             return dp[m][n] = 1 + findLengthOfLCS(x, y, m-1, n-1, dp);
//         }

//         return dp[m][n] = max(findLengthOfLCS(x, y, m-1, n, dp), findLengthOfLCS(x, y, m, n-1, dp));

//     }
// public:
//     int longestCommonSubsequence(string text1, string text2) 
//     {
//         int m = text1.size();
//         int n = text2.size();
        
//         vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        
//         return findLengthOfLCS(text1, text2, m, n, dp);
//     }
    
    public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        //need not necessary
//         for(int i=0; i<=n; i++)
//         {
//             dp[0][i] = 0;
//         }
        
//         for(int i=0; i<=m; i++)
//         {
//             dp[i][0] = 0;
//         }
        
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(text1[i-1] == text2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
        
    }
};