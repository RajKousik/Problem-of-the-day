class Solution {
public:
    
    int solve(int ind, vector<int> &jobDifficulty, int d, int n,
             vector<vector<int>> &dp)
    {
        if(ind == n and d == 0)
        {
            return 0;
        }
        
        if(ind == n or d < 0 or n-ind < d)
        {
            return 1e7;
        }
        
        if(dp[ind][d] != -1)
        {
            return dp[ind][d];
        }
        
        int maxi = INT_MIN;
        int ans = 1e7;
        
        for(int j=ind; j<n; j++)
        {
            maxi = max(maxi, jobDifficulty[j]);
            ans = min(ans, maxi + solve(j+1, jobDifficulty, d-1, n, dp));
        }
        
        return dp[ind][d] = ans;
        
    }
    
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        
        int n = jobDifficulty.size();
        
        if(n < d)
        {
            return -1;
        }
            
        vector<vector<int>> dp(n, vector<int> (d+1, -1));
        
        int ans = solve(0, jobDifficulty, d, n, dp); 
        // return ans >= 1e7 ? -1 : ans;
        
        return ans;
    }
};