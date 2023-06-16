class Solution {
public:
    // recursion + memoization
//     int helper(int i, vector<int> &cost, vector<int> &dp)
//     {
//         if(i >= cost.size())
//         {
//             return 0;
//         }
//         if(dp[i] != -1) return dp[i];
//         int pick = helper(i+1, cost, dp);
//         int notPick = helper(i+2, cost, dp);
        
//         return cost[i] + min(pick, notPick);
        
//     }
    
//     int minCostClimbingStairs(vector<int> &cost)
//     {
//         int n = cost.size();
//         vector<int> dp(n, -1);
//         return min(helper(0, cost, dp), helper(1, cost, dp));
//     }
    
    //tabulation
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();
//         vector<int> dp(n+1, -1);
//         return min(helper(n-1, cost, dp), helper(n-2, cost, dp));
//     }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, 0);
        
        for(int i=2; i<=n; i++)
        {
            int jumpOneStep = dp[i-1] + cost[i-1];
            int jumpTwoStep = dp[i-2] + cost[i-2];
            dp[i] = min(jumpOneStep, jumpTwoStep);
        }
        return dp[n];
    }
    
    //space optimization
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();
//         int prev = 0;
//         int second_prev = 0;
        
//         for(int i=2; i<=n; i++)
//         {
//             int jumpOneStep = prev + cost[i-1];
//             int jumpTwoStep = second_prev + cost[i-2];
//             second_prev = prev;
//             prev = min(jumpOneStep, jumpTwoStep);
//         }
//         return prev;
//     }
};