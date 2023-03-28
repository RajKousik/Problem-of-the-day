class Solution 
{
    
    int helper(int day, vector<int> &costs, set<int> &st, vector<int> &dp)
    {
        if(day > 365)
        {
            return 0;
        }
        
        if(dp[day] != -1)
        {
            return dp[day];
        }
        
        int ans;
        
        if(st.find(day) != st.end())
        {
            ans = min(costs[0] + helper(day + 1, costs, st, dp), costs[1] + helper(day + 7, costs, st, dp) );
            
            ans = min(ans, costs[2] + helper(day + 30, costs, st, dp));
            
        }
        else
        {
            ans = helper(day+1, costs, st, dp);
        }
        
        return dp[day] = ans;
        
    }
    
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        vector<int> dp(366, -1);
        
        set<int> st;
        for(auto it : days)
        {
            st.insert(it);
        }
        
        return helper(1, costs, st, dp);
        
    }
    
    
};