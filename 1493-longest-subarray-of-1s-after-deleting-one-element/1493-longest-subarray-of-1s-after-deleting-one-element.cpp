class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int maxLength = 0;
        int rightPtr = 0, leftPtr = 0;
        int zeroCount = 0;
        // unordered_map<int, int> umap;
        int n = nums.size();
        while(rightPtr < n)
        {
            if(nums[rightPtr] == 0)
                zeroCount++;
            
            while(zeroCount > 1)
            {
                if(nums[leftPtr] == 0)
                {
                    zeroCount--;
                }
                leftPtr++;
            }
            
            maxLength = max(maxLength, rightPtr - leftPtr + 1);
            rightPtr++;
            
        }
        
        return maxLength - 1;
    }
};