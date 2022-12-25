class Solution {
public:
    
    int find(vector<int> &arr, int ele)
    {
        int low=0, high=arr.size()-1;
        int ans = -1;
        
        while(low<=high)
        {
            int mid = (low + high)/2;
            
            if(arr[mid] <= ele)
            {
                ans = mid; 
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans + 1;
    }
    
    
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        
        
        //sort 
        //find prefix sum
        //do binary search for each query[i] and find the no of elements
        
        sort(nums.begin(), nums.end());
        
        vector<int> ans;
        
        vector<int>prefix(nums.size(), 0);
        prefix[0] = nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            prefix[i] = prefix[i-1] + nums[i];
        }
        
        for(auto ele : queries)
        {
            
            // auto it = upper_bound(prefix.begin(), prefix.end(), ele) - prefix.begin();
            
            int it = find(prefix, ele);
            
            ans.push_back(it);
            
        }
        
        return ans;
    }
};