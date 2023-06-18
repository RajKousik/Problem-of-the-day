class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int maxSum = INT_MIN;
        int sum = 0;
        //kadane's Algorithm
        for(int i=0; i<nums.size(); i++)
        {
            sum = max(sum + nums[i], nums[i]);
            maxSum = max(maxSum, sum);
        }
        
        return maxSum;
    }
};