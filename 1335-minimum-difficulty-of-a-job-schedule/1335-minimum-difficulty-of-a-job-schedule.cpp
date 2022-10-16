class Solution {
public:
    
    int solve(int ind, vector<int> &jobDifficulty, int d, int n,
             vector<vector<int>> &dp)
    {
        //if we reached the last index and also the days is 0, return 0
        if(ind == n and d == 0)
        {
            return 0;
        }
        
        //if we reached last index or
        //if days is 0
        //if n - ind < d, that means we cannot do each day atleast a single task
        //so return max value, so that will not be considered in for loop, as we r taking min value
        if(ind == n or d < 0 or n-ind < d)
        {
            return 1e7;
        }
        
        //memoization
        if(dp[ind][d] != -1)
        {
            return dp[ind][d];
        }
        
        //max is initialized to min value
        //ans is initialized to max value
        int maxi = INT_MIN;
        int ans = 1e7;
        
        //try to break in every index, and take the min
        for(int j=ind; j<n; j++)
        {
            // The difficulty of a day is the maximum difficulty of a job done on that day.
            maxi = max(maxi, jobDifficulty[j]); 
            
            // The difficulty of a job schedule is the sum of difficulties of each day of the d days. 
            //so take the max of first piece and call the recursive function for next piece
            ans = min(ans, maxi + solve(j+1, jobDifficulty, d-1, n, dp));
        }
        
        //store it and return the ans
        return dp[ind][d] = ans;
        
    }
    
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        
        
        //the intuition behind this approach is to try every state possible
        // we try to cut the array into exactly 'd pieces', and we will take the min out of those pieces
        // as we have to try every state, we should go for recursoion + memoization
        
        int n = jobDifficulty.size();
        
        
        //each day we have to do atleast one task, so if n < d, return -1
        if(n < d)
        {
            return -1;
        }
            
        // a 2-d dp array of [index, days]
        vector<vector<int>> dp(n, vector<int> (d+1, -1));
        
        //call the recursive function
        int ans = solve(0, jobDifficulty, d, n, dp);
        
        //no need of this statement, as max is initialized as INT_MAX, we will get always low value than that
        
        // return ans >= 1e7 ? -1 : ans;
        
        //return the ans
        return ans;
    }
};