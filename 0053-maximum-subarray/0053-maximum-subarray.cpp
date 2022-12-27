class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        
        int maxEndingHere = nums[0];
        int maxSoFar = nums[0];
        
        for(int i=1;i<n;i++){
            maxEndingHere = max(maxEndingHere+nums[i],nums[i]);
            maxSoFar = max(maxEndingHere,maxSoFar);
        }
        return maxSoFar;
    }
};