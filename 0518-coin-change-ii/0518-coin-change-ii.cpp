class Solution {
public:
    long long int dfs(int i, vector<int> &coins, int n, int sum, vector<vector<long long int>> &dp)
    {
        if(i == n or sum < 0)
        {
            return 0;
        }
        
        if(dp[i][sum] != -1)
        {
            return dp[i][sum];
        }
        
        if(sum == 0)
        {
            return 1;
        }
        
        long long int notPick = dfs(i+1, coins, n, sum, dp);
        long long int pick = dfs(i, coins, n, sum - coins[i], dp);
        
        return dp[i][sum] = pick + notPick;
        
        
    }
    int change(int amount, vector<int>& coins) {
        int N = coins.size();
        vector<vector<long long int >> dp(N, vector<long long int>(amount + 1, -1));
        return dfs(0, coins, N, amount, dp);
    }
};