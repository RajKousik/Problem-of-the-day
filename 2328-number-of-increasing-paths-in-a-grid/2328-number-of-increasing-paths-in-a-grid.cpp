class Solution {

private:
    
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int mod = 1e9+7;
    
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        
        //the current cell itself an answer
        int answer = 1;
        
        for(int dir=0; dir<4; dir++)
        {
            int prevI = i + dx[dir];
            int prevJ = j + dy[dir];
            
            if(prevI >= 0 and prevI < grid.size() and prevJ >= 0 and prevJ < grid[0].size() and grid[prevI][prevJ] < grid[i][j])
            {
                answer += dfs(prevI, prevJ, grid, dp);
                answer %= mod;
            }
            
        }
        
        
        return dp[i][j] = answer;
        
    }

public:
    int countPaths(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        
        int answer = 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                answer += dfs(i, j, grid, dp);
                answer %= mod;
            }
        }
        
        return answer;
        
    }
};