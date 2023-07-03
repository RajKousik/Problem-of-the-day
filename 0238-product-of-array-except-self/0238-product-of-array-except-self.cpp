class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), zeroCount = 0, product = 1; 
        
        for(auto it : nums)
        {
            if(it == 0) zeroCount++;
            else product *= it;
        }
        
        vector<int> ans(n, 0);
        
        if(zeroCount > 1)
            return ans;
        
        //edge case : input [-1,1,0,-3,3]
        //expected o/p : [0,0,9,0,0]
        
        for(int i=0; i<n; i++)
        {
            if(zeroCount)
            {
                if(nums[i] == 0) 
                {
                    ans[i] = product;
                }
                else
                {
                    ans[i] = 0;
                }
            }
            else
                ans[i] = product/nums[i];
        }
        return ans;
    }
};