class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n = nums.size();
        
        int leftPtr = 0;
        int midPtr = 0;
        int rightPtr = n-1;
        
        while(midPtr <= rightPtr)
        {
            if(nums[midPtr] == 0)
            {
                swap(nums[leftPtr++], nums[midPtr++]);
            }
            else if(nums[midPtr] == 1)
            {
                midPtr++;
            }
            else
            {
                swap(nums[midPtr], nums[rightPtr--]);
            }
        }
        
    }
};