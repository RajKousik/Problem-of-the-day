class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        
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
            
            auto it = upper_bound(prefix.begin(), prefix.end(), ele) - prefix.begin();
            
            ans.push_back(it);
            
        }
        
        return ans;
    }
};