class Solution {
private:
    
    int rob_util(int index, vector<int> &nums, vector<int> &dp)
    {
        if(index >= nums.size())
        {
            return 0;
        }
        
        if(dp[index] != -1)
        {
            return dp[index];
        }
        
        int pick = nums[index] + rob_util(index+2, nums, dp);
        int notPick = rob_util(index+1, nums, dp);
        
        return dp[index] = max(pick, notPick);
        
    }
    
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return rob_util(0, nums, dp);
        
    }
};