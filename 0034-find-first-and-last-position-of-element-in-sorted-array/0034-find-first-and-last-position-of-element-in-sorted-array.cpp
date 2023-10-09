class Solution {
public:
    
//     int findOnLeftBS(int l, int r, vector<int> &nums, int target)
//     {
//         int ans = -1;
//         while(l <= r)
//         {
//             int mid = l + (r - l)/2;
            
//             if(nums[mid] == target)
//             {
//                 ans = mid;
//                 r = mid - 1;
//             }
//             else if(nums[mid] > target)
//             {
//                 r = mid - 1;
//             }
//             else
//             {
//                 l = mid + 1;
//             }
//         }
//         return ans;
        
//     }
    
//     int findOnRightBS(int l, int r, vector<int> &nums, int target)
//     {
//         int ans = -1;
//         while(l <= r)
//         {
//             int mid = l + (r - l)/2;
            
//             if(nums[mid] == target)
//             {
//                 ans = mid;
//                 l = mid + 1;
//             }
//             else if(nums[mid] < target)
//             {
//                 l = mid + 1;
//             }
//             else
//             {
//                 r = mid - 1;
//             }
//         }
//         return ans;
        
//     }
    
    vector<int> searchRange(vector<int>& nums, int target)
    {
//         vector<int> ans(2);
//         int n = nums.size();
        
//         ans[0] = findOnLeftBS(0 , n-1, nums, target);
            // if(ans[0] == -1)
            // {
            //     return {-1, -1}; 
            // }
//         ans[1] = findOnRightBS(0 , n-1, nums, target);
        
//         return ans;
        
        auto lower = lower_bound(nums.begin(), nums.end(), target);
        auto upper = upper_bound(nums.begin(), nums.end(), target);
        
        if(lower == nums.end() or *lower != target)   
            return {-1, -1};
        
        int first = lower - nums.begin();
        int last = upper - nums.begin() - 1;
        
        return {first, last};
        
        
    }
};