class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        
        int n = nums.size();
        
        vector<vector<int>> pairs(n, vector<int>(2));
        
        for(int i=0; i<n; i++)
        {
            pairs[i][0] = nums[i];
            pairs[i][1] = cost[i];
        }
        
        sort(pairs.begin(), pairs.end());
        
        vector<long long> prefix(n);
        prefix[0] = pairs[0][1];
        
        for(int i=1; i<n; i++)
        {
            prefix[i] = pairs[i][1] + prefix[i-1];
        }
        
        long long totalCost = 0;
        
        for(int i=1; i<n; i++)
        {
            totalCost += 1LL * pairs[i][1] * (pairs[i][0] - pairs[0][0]);
        }
        
        long long answer = totalCost;

        
        for(int i=1; i<n; i++)
        {
            int gap = pairs[i][0] - pairs[i-1][0];
            totalCost += 1LL * prefix[i-1] * gap;
            totalCost -= 1LL * (prefix[n-1] - prefix[i-1]) * gap;
            answer = min(answer, totalCost);
        }
        
        return answer;
        
    }
};