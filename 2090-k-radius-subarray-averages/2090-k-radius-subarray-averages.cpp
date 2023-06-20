class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, -1);
        
        if (2 * k + 1 > n) {
            return ans;
        }
        
        vector<long long> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        
        for(int i=1; i<n; i++)
        {
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }
        
        for(int i=k; i<(n-k); i++)
        {
            long long sum = 0;
            int avg = -1;
            if((i-k >= 0) and (i+k < n ) )
            {
                sum += prefixSum[i+k];
                if(i-k-1 >= 0) sum -= prefixSum[i-k-1];
                avg = (int)(sum/(2*k + 1));
            }
            ans[i] = avg;
            
        }
        
        return ans;
    }
};