class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int ans = INT_MAX;
        int sum = 0;
        int n = nums.size();
        
        int leftPtr=0, rightPtr=0;
        
        while(rightPtr < n)
        {
            sum += nums[rightPtr];
            
            while(sum >= target)
            {
                ans = min(ans, rightPtr - leftPtr + 1);
                sum -= nums[leftPtr];
                leftPtr++;
            }
            
            rightPtr++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};