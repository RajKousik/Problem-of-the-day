class Solution 
{
private:
    
    int helper(int i, int j, string &s, vector<vector<int>> &dp)
    {
        if(i > j)
        {
            return 0;
        }
        
        if(i == j)
        {
            return 1;
        }
        
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        
        if(s[i] == s[j])
        {
            return dp[i][j] = helper(i+1, j-1, s, dp) + 2;
        }
        else
        {
            return dp[i][j] = max(helper(i+1, j, s, dp), helper(i, j-1, s, dp));
        }
        
        return dp[i][j];
    }

public:
    int longestPalindromeSubseq(string s) 
    {
        
        int n = s.size();
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        return helper(0, n-1, s, dp);
        
    }
};