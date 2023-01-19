class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int ans = 0;
        int preSum = 0;
        
        unordered_map<int, int> umap;
        umap[0] = 1;
        
        for(auto it : nums)
        {
            // preSum += it;
            preSum = ( preSum + it % k + k) % k;
            // preSum = (preSum + k) % k;
            
            if(umap.find(preSum) != umap.end())
            {
                ans += umap[preSum];
            }
            umap[preSum]++;
        }
        
        return ans;
        
    }
};