class Solution {
public:
    
    //feeling proud, solved without viewing solution
    
    
    int mod = (int)1e9+7;
    
    //Recursion + memoization
    
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
    
    //Tabulation
//     int numRollsToTarget(int n, int k, int target) {
        
//         vector<vector<long long>> dp(n+1, vector<long long>(target+1, 0));
        
//         dp[0][0] = 1;
        
//         long long ans = 0;
        
//         for(int dice = 1; dice <= n; dice++)
//         {
//             for(int tar = 1; tar <= target; tar++)
//             {
//                 for(int roll=1; roll <= k and tar - roll >= 0 ; roll++)
//                 {
//                     dp[dice][tar] += (dp[dice-1][tar-roll] % mod);
//                 }
//             }
//         }
        
//         return dp[n][target] % mod;
        
//     }
    
    //Space Optimized Approach
    int numRollsToTarget(int n, int k, int target) {
        
        vector<long long> prev(target+1, 0);
        vector<long long> curr(target+1, 0);
        
        prev[0] = 1;
        
        long long ans = 0;
        
        for(int dice = 1; dice <= n; dice++)
        {
            
            for(int t = 1; t <= target; t++)
            {
                
                ans = 0;
                for(int roll = 1; roll <= k and t - roll >= 0; roll++)
                {
                    ans += (prev[t-roll] % mod);
                }
                curr[t] = ans % mod;
                
            }
            
            prev = curr;
        }
        
        return prev[target] % mod;
        
    }
    
    
};