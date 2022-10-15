class Solution {
public:
    
    //not using INT_MAX as we r doing INT_MAX + some value, which will give Runtime Error
    //max value
    const int MAX = 100;
    
    inline int find_len(int x)
    {
        if(x == 1)
        {
            return 0;
        }
        else if(x < 10)
        {
            return 1;
        }
        else if(x < 100)
        {
            return 2;
        }
        else if(x < 1000)
        {
            return 3;
        }
        return 4;
    }
    
    int solve(int index, int k, string &s, int n, vector<vector<int>> &dp)
    {
        if(k < 0)
        {
            return MAX;
        }
        
        if(index >= n or n - index <= k)
        {
            return 0;
        }
        
        if(dp[index][k] != -1)
        {
            return dp[index][k];
        }
        
        vector<int> freq(26, 0);
        int most_freq = 0;
        int ans = MAX;
        
        for(int j=index; j<n; j++)
        {
            most_freq = max(most_freq, ++freq[s[j] - 'a']);
            ans = min(ans, 1 + find_len(most_freq) + solve(j+1, k-(j-index+1-most_freq), s, n, dp) );
        }
        
        return dp[index][k] = ans;
        
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        
        vector<vector<int>> dp(101, vector<int>(101, -1));
        
        int n = s.size();
        
        return solve(0, k, s, n, dp);
        
    }
};