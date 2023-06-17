class Solution {
private:
    
    int dfs(int index, int prev, vector<int> &arr1, vector<int> &arr2, map< pair<int, int>, int> &dp)
    {
        if(index == arr1.size())
        {
            return 0;
        }
        
        if(dp.find({index, prev}) != dp.end())
        {
            return dp[{index, prev}];
        }
        
        int cost = 2001;  //since arr length is at max 2000
        
        if(arr1[index] > prev)
        {
            cost = dfs(index + 1, arr1[index], arr1, arr2, dp);
        }
        
        int indexOfArr2 = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();
        
        if(indexOfArr2 < arr2.size())
        {
            cost = min(cost, 1 + dfs(index + 1, arr2[indexOfArr2], arr1, arr2, dp));
        }
        
        return dp[{index, prev}] = cost;
        // return cost;
        
        
    }
    
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) 
    {
        int n = arr1.size();
        sort(arr2.begin(), arr2.end());
        
        // vector<vector<int>> dp(2001, vector<int>(2001, -1));
        map< pair<int, int>, int> dp;
        
        int prev = -1;
        int answer = dfs(0, prev, arr1, arr2, dp);
        
        return answer < 2001 ? answer : -1;
    }
};