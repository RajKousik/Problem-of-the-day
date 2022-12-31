class Solution {
public:
    
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    
    void dfs(int x, int y, vector<vector<int>> &grid, int &ans, int steps, int count)
    {
        if(x < 0 or x >= grid.size() or y < 0 or y >= grid[0].size() or grid[x][y] == -1)
        {
            return;
        }
        
        if(grid[x][y] == 2)
        {
            if(steps == count)
            {
                ans++;
            }
            return;
        }
        
        
        grid[x][y] = -1;
        
        for(int k=0; k<4; k++)
        {
            int newX = x + dx[k];
            int newY = y + dy[k];
            
            dfs(newX, newY, grid, ans, steps+1, count);
        }
        
        grid[x][y] = 0;
    }
    
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        int count = 1;
        int startX, startY;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 0)
                {
                    count++;
                }
                if(grid[i][j] == 1)
                {
                    startX = i;
                    startY = j;
                }
            }
        }
        
        int ans = 0;
        dfs(startX, startY, grid, ans, 0, count);
        
        return ans;
        
        
    }
};