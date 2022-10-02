class Solution {
public:
    int mod = (int)1e9+7;
//     int helper(int n, int k, int target, vector<vector<int>> &dp)
//     {
//         if(n < 0 or target < 0)
//         {
//             return 0;
//         }
        
//         if(n == 0 and target == 0)
//         {
//             return 1;
//         }
        
//         if(dp[n][target] != -1)
//         {
//             return dp[n][target];
//         }
        
//         long long ans = 0;
        
//         for(int i=1; i<=k; i++)
//         {
//             ans = ans + (helper(n-1, k, target - i, dp) % mod);
//         }
        
//         return dp[n][target] = (ans % mod);
        
//     }
    
    
//     int numRollsToTarget(int n, int k, int target) {
        
//         vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        
//         return helper(n, k, target, dp);
        
//     }
    int numRollsToTarget(int n, int k, int target) {
        
        vector<vector<long long>> dp(n+1, vector<long long>(target+1, 0));
        
        dp[0][0] = 1;
        
        // long long ans = 0;
        
        for(int num = 1; num <= n; num++)
        {
            for(int tar = 1; tar <= target; tar++)
            {
                for(int i=1; i<=k and tar - i >= 0 ; i++)
                {
                    dp[num][tar] += (dp[num-1][tar-i] % mod);
                    // cout<<" "<<i<<" ";
                }
            }
        }
        
        return dp[n][target] % mod;
        
    }
    
    
};