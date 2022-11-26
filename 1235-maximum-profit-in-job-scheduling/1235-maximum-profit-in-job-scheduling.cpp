class Solution {
public:
    
    int func(int index, vector<pair<int, pair<int, int>>> &arr, vector<int> &dp, int n)
    {
        if(index >= n)
        {
            return 0;
        }
        
        if(dp[index] != -1)
        {
            return dp[index];
        }
        
        int start = arr[index].first;
        int end = arr[index].second.first;
        int profit = arr[index].second.second;
        
        pair<int, pair<int, int>> p = {end, {0, 0}};
        
        int nextIdx = lower_bound(arr.begin(), arr.end(), p) - arr.begin();
        
        int pick = profit + func(nextIdx, arr, dp, n);
        int notPick = func(index+1, arr, dp, n);
        
        return dp[index] = max(pick, notPick); 
        
    }
    
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        
        vector<pair<int, pair<int, int>>> arr(n, {0, {0, 0}});
        
        for(int i=0; i<n; i++)
        {
            arr[i] = {startTime[i], {endTime[i], profit[i]}};
        }
        
        vector<int> dp(n+1, -1);
        
        sort(arr.begin(), arr.end());
        
        return func(0, arr, dp, n);
        
    }
};