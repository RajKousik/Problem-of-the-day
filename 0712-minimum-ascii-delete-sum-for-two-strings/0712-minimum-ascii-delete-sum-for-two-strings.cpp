class Solution {
public:
    
    int lcs(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
    {
        if(i < 0 or j < 0)
        {
            return 0;
        }

        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if(s1[i] == s2[j])
        {
            return dp[i][j] = s1[i] + lcs(s1, s2, i-1, j-1, dp);
        }
        else
        {
            return dp[i][j] = max(lcs(s1, s2, i-1, j, dp), lcs(s1, s2, i, j-1, dp));
        }
        return -1;
    }
    
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        
        int sum1 = 0, sum2 = 0;
        
        for(char ch : s1)
        {
            sum1 += ch;
        }
        
        for(char ch : s2)
        {
            sum2 += ch;
        }
        
        int sumOfLCS = lcs(s1, s2, m-1, n-1, dp);
        
        return sum1 + sum2 - (2 * sumOfLCS);
    }
};