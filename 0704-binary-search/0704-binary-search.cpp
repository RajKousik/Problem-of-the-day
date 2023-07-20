class Solution {
public:
    
    int binary_search(int low, int high, vector<int> &nums, int target)
    {
        if(low <= high)
        {
            int mid = (low + high)/2;
            
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] > target)
            {
                return binary_search(low, mid - 1, nums, target);
            }
            else
            {
                return binary_search(mid + 1, high, nums, target);
            }
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
//         int l=0, h=nums.size()-1;
        
//         while(l <= h)
//         {
//             int mid = l + (h-l)/2;
            
//             if(nums[mid] == target)
//             {
//                 return mid;
//             }
//             else if(nums[mid] > target)
//             {
//                 h = mid - 1;
//             }
//             else
//             {
//                 l = mid + 1;
//             }
//         }
//         return -1;
        int n = nums.size();
        int result = binary_search(0, n-1, nums, target);
        return result;
        
    }
};