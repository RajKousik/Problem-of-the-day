class Solution {
public:
    
//     int ceil(vector<int> arr, int l, int h, int x)
//     {
//         int ans;
//         while(l <= h)
//         {
//             int mid = l + (h-l)/2;
            
//             if(arr[mid] >= x)
//             {
//                 ans = mid;
//                 h = mid - 1;
//             }
//             else
//             {
//                 l = mid + 1;
//             }
//         }
//         return ans;
//     }
    
//     int lengthOfLIS(vector<int>& nums)
//     {
//         vector<int> v;
        
//         v.push_back(nums[0]);
        
//         for(int i=1; i<nums.size(); i++)
//         {
            
//             if(nums[i] > v[v.size()-1])
//             {
//                 v.push_back(nums[i]);
//             }
//             else
//             {
//                 // auto index = lower_bound(v.begin(), v.end(), nums[i]);
//                 // *index = nums[i];
                
//                 //ceil function is equal to lower_bound
//                 //we can use that also, both will work
//                 int index = ceil(v, 0, v.size()-1, nums[i]);
//                 v[index] = nums[i];
//             }
            
//         }
//         //dry run
//         //keep on adding into the v array if larger values of found
//         //smaller value found means, find the index of that smallest element in the v array, and add it
//         //return the size of the v array which holds the increasing sequence
//         return v.size();
//     }
    
    
    
    
    
    int helperFunction(int index, int previousIndex, vector<int> &nums, vector<vector<int>> &dp)
    {
        if(index == nums.size())
        {
            return 0;
        }
        
        if(dp[index][previousIndex + 1] != -1)
        {
            return dp[index][previousIndex + 1];
        }
        
        int dontTake = helperFunction(index+1, previousIndex, nums, dp);
        
        int take = 0;
        
        if(previousIndex == -1 or nums[index] > nums[previousIndex])
        {
            take = 1 + helperFunction(index+1, index, nums, dp);
        }
        
        return dp[index][previousIndex + 1] = max(take, dontTake);
        
    }
    

    
    
    int lengthOfLIS(vector<int>& nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        int previousIndex = -1;
        return helperFunction(0, previousIndex, nums, dp);
        
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
};