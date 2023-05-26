class Solution {

private:
    
    int helper(int player, int ind, int m, vector<int> &piles, int n, vector<vector<vector<int>>> &dp)
    {
        if(ind == n)
        {
            return 0;
        }
        
        
        if(dp[player][ind][m] != -1)
        {
            return dp[player][ind][m];
        }
        
        int res = player == 1 ? 1e6 : -1;
        
        int s = 0;
        
        for(int x = 1; x <= min(2*m, n-ind); x++)
        {

            s += piles[ind + x - 1];
            if(player == 0)
            {
                res = max(res, s + helper(1, ind + x, max(m, x), piles, n, dp));
            }
            else
            {
                res = min(res, helper(0, ind + x, max(m, x), piles, n, dp));
            }
                    
        }
        return dp[player][ind][m] = res;
    }
    
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n+1, vector<int>(n+1, -1)));
        
        return helper(0, 0, 1, piles, n, dp);
        
    }
};