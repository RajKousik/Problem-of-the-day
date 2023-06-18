class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int zeroCount = 0;
        int product = 1; 
        for(auto it : nums)
        {
            if(it == 0) zeroCount++;
            else product *= it;
        }
        if(zeroCount > 1)
        {
            vector<int> ans(n, 0);
            return ans;
        }
        vector<int> ans(n, 0);
        for(int i=0; i<n; i++)
        {
            if(zeroCount)
            {
                if(nums[i] == 0) 
                {
                    ans[i] = product;
            
                }
            }
            else
                ans[i] = product/nums[i];
        }
        return ans;
    }
};