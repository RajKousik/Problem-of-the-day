class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        
        //the onlt constraint is a + b > c
        
        //so we need largest perimeter, so we will sort first, and iterate in reverse direction, so we will get the largest one
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        for(int i=n-3; i>=0; i--)
        {
            if(nums[i] + nums[i+1] > nums[i+2])
            {
                return nums[i] + nums[i+1] + nums[i+2];
            }
        }
        
        return 0;
        
    }
};