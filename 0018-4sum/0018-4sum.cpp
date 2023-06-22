class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //2 pointers and binary  search
        vector<vector<int>> res;
        if(nums.empty()){
            return res;
        }
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n; i++)
        {
            
            for(int j=i+1; j<n; j++)
            {
                
                int low = j+1, high = n-1;
                long long ourTarget = target - nums[j];
                ourTarget -= nums[i];
                
                while(low < high)
                {
                    
                    long long sum_two = nums[low] + nums[high];
                    
                    if(sum_two < ourTarget){
                        low++;
                    }
                    else if(sum_two > ourTarget){
                        high--;
                    }
                    else
                    {
                        vector<int> quad(4, 0);
                        quad[0] = nums[i];
                        quad[1] = nums[j];
                        quad[2] = nums[low];
                        quad[3] = nums[high];
                        res.push_back(quad);
                        
                        while(low+1 < high && nums[low]==nums[low+1])
                        {
                            low++;
                        }
                        
                        while(high - 1 > high && nums[high]==nums[high-1])
                        {
                            high--;
                        }
                        
                        low++;
                        high--;
                        
                    }
                    
                }
                
                while( j+1 < n && nums[j+1] == nums[j] )
                {
                    j++;
                }
                
            }
            
            while( i+1 < n && nums[i+1] == nums[i] )
            {
                    i++;
            }
            
        }
        
        return res;
    }
};