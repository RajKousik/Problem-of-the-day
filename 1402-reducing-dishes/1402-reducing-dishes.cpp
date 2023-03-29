class Solution {
public:
    
    int helper(int arrIndex, int mul, vector<int>& satisfaction, vector<vector<int>> &dp)
    {
        if(arrIndex == satisfaction.size())
        {
            return 0;
        }
        
        if(dp[arrIndex][mul] != -1)
        {
            return dp[arrIndex][mul];
        }
        
        int pick = (satisfaction[arrIndex] * mul) + helper(arrIndex+1, mul+1, satisfaction, dp);
        
        int notPick = helper(arrIndex+1, mul, satisfaction, dp);
        
        return dp[arrIndex][mul] = max(pick, notPick);
        // return max(pick, notPick);
    }
    
    int maxSatisfaction(vector<int>& satisfaction)
    {
        sort(satisfaction.begin(), satisfaction.end());
        
        vector<vector<int>> dp(satisfaction.size() + 1, vector<int> (satisfaction.size() + 1 , -1));
        
        return helper(0, 1, satisfaction, dp);
        // return ans;
    }
};