class Solution {
    bool checkForAllStars(string &s, int index)
    {
        for(int i=0; i<=index; i++)
        {
            if(s[i] != '*') return false;
        }
        return true;
    }
    
    bool dfs(int i, int j, string &s, string &p, vector<vector<int>> &dp)
    {
        // cout<<i<<" "<<j<<endl;
        if(i < 0 and j < 0)
        {
            return 1;
        }
        if(j < 0 and i >= 0)
        {
            return 0;
        }
        if(i < 0 and j >=0 )
        {
            return checkForAllStars(p, j);
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if(s[i] == p[j] or p[j] == '?')
        {
            return dp[i][j] = dfs(i-1, j-1, s, p, dp);
        }
        else
        {
            if(p[j] == '*')
            {
                
                return dp[i][j] = (dfs(i-1, j, s, p, dp) or dfs(i, j-1, s, p, dp));
            }
            else
            {
                return dp[i][j] = 0;
            }
        }
        return dp[i][j] = 0;
    }
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return dfs(m-1, n-1, s, p, dp);
    }
};