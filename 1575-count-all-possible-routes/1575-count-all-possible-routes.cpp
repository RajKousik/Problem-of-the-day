class Solution {
    
    int dfs(int currCity, int finish, vector<int> &locations, int fuel, 
           vector<vector<int>> &dp)
    {
        
        if(fuel < 0)
        {
            return 0;
        }
        
        if(dp[currCity][fuel] != -1)
        {
            return dp[currCity][fuel];
        }
        
        int ans = currCity == finish ? 1 : 0;
        
        for(int nextCity = 0; nextCity < locations.size(); nextCity++)
        {
            if(nextCity != currCity)
            {
                ans = (ans + dfs(nextCity, finish, locations, fuel - abs(locations[currCity] - locations[nextCity]), dp)) % 1000000007;
            }
        }
        
        return dp[currCity][fuel] = ans;
        
    }
    
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        
        int n = locations.size();
        
        vector<vector<int>> dp(n, vector<int>(fuel+1, -1));
        
        return dfs(start, finish, locations, fuel, dp);
        
    }
};