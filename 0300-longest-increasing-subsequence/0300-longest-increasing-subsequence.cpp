class Solution {
public:
    
    int ceil(vector<int> arr, int l, int h, int x)
    {
        int ans;
        while(l <= h)
        {
            int mid = l + (h-l)/2;
            
            if(arr[mid] >= x)
            {
                ans = mid;
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    }
    
    int lengthOfLIS(vector<int>& nums)
    {
        vector<int> v;
        
        v.push_back(nums[0]);
        
        for(int i=1; i<nums.size(); i++)
        {
            
            if(nums[i] > v[v.size()-1])
            {
                v.push_back(nums[i]);
            }
            else
            {
                // auto index = lower_bound(v.begin(), v.end(), nums[i]);
                // *index = nums[i];
                
                //ceil function is equal to lower_bound
                //we can use that also, both will work
                int index = ceil(v, 0, v.size()-1, nums[i]);
                v[index] = nums[i];
            }
            
        }
        //dry run
        //keep on adding into the v array if larger values of found
        //smaller value found means, find the index of that smallest element in the v array, and add it
        //return the size of the v array which holds the increasing sequence
        return v.size();
    }
};