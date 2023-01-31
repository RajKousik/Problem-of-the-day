class Solution {
private:

int func(int ind, int prevIndex, vector<pair<int, int>> &arr, vector<vector<int>> &dp, int n)
{
    if(ind >= n)
    {
        return 0;
    }
    
    if(dp[prevIndex + 1][ind] != -1)
    {
        return dp[prevIndex + 1][ind];
    }
    
    if( (prevIndex == -1) or (arr[ind].second >= arr[prevIndex].second) )
    {
        return max( func(ind+1, prevIndex, arr, dp, n), 
                  arr[ind].second + func(ind+1, ind, arr, dp, n)  );
    }    
    
    return dp[prevIndex + 1][ind] = func(ind+1, prevIndex, arr, dp, n);
    
}

public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
                
        int n = scores.size();        
        vector<pair<int, int>> arr(n);

        for(int i=0; i<n; i++)
        {
            arr[i] = {ages[i], scores[i]};
        }
        
        sort(arr.begin(), arr.end());
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        return func(0, -1, arr, dp, n);
        
    }
};