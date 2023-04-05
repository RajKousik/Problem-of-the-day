class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        
        long long ans = 0;
        
        long long prefixSum = 0;
        
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            prefixSum += nums[i];
            ans = max(ans, (prefixSum+i)/(i+1));
        }
        
        return ans;
        
    }
};