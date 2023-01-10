class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        
        int n = nums.size();
        
        for(int i=0; i<n-2; i++)
        {
            
            int low = i + 1;
            int high = n - 1;
            
            int target = nums[i];
            
            while(low < high)
            {
                
                if(target + nums[low] + nums[high] == 0)
                {
                    ans.push_back({target, nums[low], nums[high]});
                    while(low + 1 < n and nums[low] == nums[low+1])
                    {
                        low++;
                    }
                    while(high - 1 >=0 and nums[high] == nums[high-1])
                    {
                        high--;
                    }
                    low++;
                    high--;
                }
                else if(target + nums[low] + nums[high] < 0)
                {
                    low++;
                }
                else
                {
                    high--;
                }
                
                
                
            }
            
            while(i + 1< n and nums[i] == nums[i+1])
            {
                i++;
            }
            
        }
        
        return ans;
    }
};