class Solution {
    
    string dfs(vector<int> &cost, int target, vector<string> &dp)
    {
        if(target < 0)
        {
            return "0";
        }
        if(target == 0)
        {
            return "";
        }
        
        if(dp[target] != "") return dp[target];
        
        string ans = "0";
        
        for(int d=9; d>0; d--)
        {
            string curr = dfs(cost, target - cost[d-1], dp);
            
            if(curr == "0") continue;
            
            curr = to_string(d) + curr;
            if (ans == "0" || curr.size() > ans.size()) {
                ans = curr;
            }
            
        }
        
        return dp[target] = ans;
        
    }
    
public:
    string largestNumber(vector<int>& cost, int target) {
        
        vector<string> dp(target + 1);
        for(int i=0; i<=target; i++)
        {
            dp[i] = "";
        }
        return dfs(cost, target, dp);
        
    }
};