class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        long long int ans = 0;
        int minPosition = -1;
        int maxPosition = -1;
        int leftBound = -1;
        
        int n = nums.size();
        
        for(int i=0; i<n; i++)
        {
            if(nums[i] < minK or nums[i] > maxK)
            {
                leftBound = i;
            }
            
            if(nums[i] == minK)
            {
                minPosition = i;
            }
            
            if(nums[i] == maxK)
            {
                maxPosition = i;
            }
            
            ans += max(0, min(minPosition, maxPosition) - leftBound);
            
        }
        
        return ans;
        
    }
};