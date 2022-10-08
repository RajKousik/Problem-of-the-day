class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int ans;
        int minDiff = INT_MAX;
        
        for(int i=0; i<n-2; i++)
        {
            int j = i+1;
            int k = n-1;
            
            
            
            
            while(j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                
                int diff = abs(sum - target);
                
                if(diff < minDiff)
                {
                    // cout<<minDiff<<" "<<diff<<" ";
                    minDiff = diff;
                    // cout<<minDiff<<" "<<diff<<" ";
                    ans = sum;
                    
                    // cout<<ans<<" "<<endl;
                }
                
                if(sum < target)
                {
                    j++;
                }
                else if(sum > target)
                {
                    k--;
                }
                else
                {
                    return sum;
                }
                
            }
        }
        return ans;
    }
};