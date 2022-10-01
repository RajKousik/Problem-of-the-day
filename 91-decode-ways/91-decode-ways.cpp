class Solution {
public:
    
    int helper(int ind, string s, vector<int> &dp, int n)
    {
        
        if(ind == n)
        {
            return 1;
        }
        
        if(dp[ind] != -1)
        {
            return dp[ind];
        }
        
        if(s[ind] == '0')
        {
            return 0;
        }
        
        int res = helper(ind + 1, s, dp, n);
        
        if(ind < n-1 and (s[ind] == '1' or (s[ind] =='2' and s[ind+1] <= '6') ) )
        {
            res += helper(ind + 2, s, dp, n);
        }
        
        return dp[ind] = res;
        
        
    }
    
    
    int numDecodings(string s) 
    {
        if(s.empty())
        {
            return 0;
        }
        int n = s.size();
        
        vector<int> dp(n+1, -1);
        
        return helper(0, s, dp, n);
    }
};