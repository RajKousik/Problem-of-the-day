class Solution {
    
    int longestPalindromicSubsequence(int i, int j, string &A, string &B, vector<vector<int>> &dp)
    {

        if(i == 0 or j == 0)
        {
            return 0;
        }

        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if(A[i-1] == B[j-1])
        {
            return dp[i][j] = 1 + longestPalindromicSubsequence(i-1, j-1, A, B, dp);
        }

        return dp[i][j] = max(longestPalindromicSubsequence(i-1, j, A, B, dp),
                  longestPalindromicSubsequence(i, j-1, A, B, dp));

    }
    
    
public:
    int minInsertions(string A)
    {
        int n = A.size();
	
        string B = A;
        reverse(B.begin(), B.end());

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        return (n- longestPalindromicSubsequence(n, n, A, B, dp)); 
        
        
        
    }
};