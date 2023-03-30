class Solution {
public:
    bool isScramble(string s1, string s2) 
    {
        int n = s1.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n, vector<int>(n, 0)));
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                dp[1][i][j] = (s1[i] == s2[j]);
            }
        }
        
        for(int length = 2; length <= n; length++)
        {
            for(int i = 0 ; i < n + 1 - length; i++)
            {
                for(int j = 0; j < n + 1 - length; j++)
                {
                    
                    for(int newLength = 1; newLength < length; newLength++)
                    {
                        
                        bool noSwap = dp[newLength][i][j] and dp[length - newLength][i + newLength][j + newLength];
                        
                        bool swap = dp[newLength][i][j + length - newLength] and dp[length - newLength][i + newLength][j];
                        
                        dp[length][i][j] |= swap or noSwap;
                        
                    }
                    
                }
            }
        }
        
        return dp[n][0][0];
        
    }
};