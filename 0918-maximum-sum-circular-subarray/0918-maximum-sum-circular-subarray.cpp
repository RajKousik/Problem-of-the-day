class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        /*
            Maximum Sum Circular Subarray is the maximum of two answers
                1. maximum subarray sum of kadane algo
                2. total sum - minimum subarray

            So we have to find maxsum using kadane algo and minimum subarray
            max of two answers is the result

            If all the numbers present in the given array is negative, then we have to 
            return the maximum element in the array

            So calculate total sum, and check it is negative, if negative then return maxElement
            else return max(Kadane Ans, totalSum - Minimum Subarray Sum)
        
        */
        
        int totalSum = 0;
        
        int maxSum = INT_MIN;  //kadane algo
        int minSum = INT_MAX;
        
        int curMax = 0;
        int curMin = 0;
        
        for(auto it : nums)
        {
            totalSum += it;
            
            curMax = max(curMax + it, it);
            maxSum = max(maxSum, curMax);
            cout<<maxSum<<" ";
            
            curMin = min(curMin + it, it);
            minSum = min(minSum, curMin);
        }
        
        return maxSum < 0 ? maxSum : max(maxSum, totalSum - minSum);
        
        
    }
};