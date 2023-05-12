class Solution 
{
    long long dfs(vector<vector<int>> &questions, int index, vector<long long> &dp)
    {
        
        if(index >= questions.size())
        {
            return 0;
        }
        
        if(dp[index] != -1)
        {
            return dp[index];
        }
        
        long long points = questions[index][0];
        long long skip = questions[index][1];
        
        return dp[index] = max(points + dfs(questions, index + skip + 1, dp), dfs(questions, index+1, dp));
        
    }
    
    
public:
    long long mostPoints(vector<vector<int>>& questions)
    {
        
        int n = questions.size();
        
        vector<long long> dp(n, -1);
        
        return dfs(questions, 0, dp);
        
        
    }
};