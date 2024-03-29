class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans;    
        while(low <= high)
        {
            int mid = (low + high)/2;
            
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] < target)
            {
                ans = low;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        // return high + 1;
        return low;
        
    }
};