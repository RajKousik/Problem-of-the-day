class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int n = nums.size();
        int maxi = 0;
        int right=0, left = 0;
        
        int zeroCount = 0;
        
        while(right < n)
        {
            if(nums[right] == 0)
            {
                zeroCount++;
            }
            while(zeroCount > 1)
            {
                if(nums[left] == 0)
                {
                    zeroCount--;
                }
                left++;
            }
            maxi = max(maxi, right - left + 1);
            right++;
        }
        return maxi-1;
    }
};