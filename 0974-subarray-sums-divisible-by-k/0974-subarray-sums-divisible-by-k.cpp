class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        // vector<int> remainders(k, 0);
        unordered_map<int, int> umap;
        int prefixSum = 0;
        
        umap[0] = 1;
        int ans = 0;
        
        for(int num : nums)
        {
            
            prefixSum = (prefixSum + num) % k;
            prefixSum = (prefixSum + k) % k;  //too handle negative numbers
            
            // if(umap.find(prefixSum) != umap.end())
            // {
                ans += umap[prefixSum];
            // }
            
            umap[prefixSum]++;
            
        }
        
        return ans;
        
    }
};