class Solution {

private:
    
    void dfs(int x, int y, vector<vector<int>> &grid, int m, int n,
            queue<pair<int, int>> &q)
    {
        if(x < 0 or x >= m or y < 0 or y >= n or grid[x][y] != 1)
        {
            return;
        }
        
        q.push({x, y});
        grid[x][y] = 2;
        
        dfs(x-1, y, grid, m, n, q);
        dfs(x+1, y, grid, m, n, q);
        dfs(x, y-1, grid, m, n, q);
        dfs(x, y+1, grid, m, n, q);
        
    }
    
public:
    int shortestBridge(vector<vector<int>>& grid) 
    {
        
        
        
        int startX, startY;
        
        int m = grid.size();
        int n = grid[0].size();
        
        bool isOneFound = false;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1)
                {
                    startX = i, startY = j;
                    isOneFound = true;
                    break;
                }
            }
            if(isOneFound) break;
        }
        
        // cout<<startX<<" "<<startY<<endl;
        
        queue<pair<int, int>> q;
        dfs(startX, startY, grid, m, n, q);
        
        int flips = 0;
        
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        
        
        // for(auto it : grid)
        // {
        //     for(auto ele : it)
        //     {
        //         cout<<ele<<" ";
        //     }
        //     cout<<endl;
        // }
        
        // while(!q.empty())
        // {
        //     cout<<q.front().first<<" "<<q.front().second<<endl;
        //     q.pop();
        // }
        
        while(!q.empty())
        {
            int size = q.size();
            
            while(size--)
            {
                
                auto node = q.front();
                q.pop();
                
                
                
                int x = node.first;
                int y = node.second;
                
                cout<<x<<" "<<y<<endl;
                
                if(grid[x][y] == 1)
                {
                    return flips;
                }
                
                for(int dir=0; dir<4; dir++)
                {
                    int newX = x + dx[dir];
                    int newY = y + dy[dir];
                    
                    if(newX >=0 and newX < m and newY>=0 and newY < n and grid[newX][newY] != -1)
                    {
                        if(grid[newX][newY] == 0)
                        {
                            grid[newX][newY] = -1;
                            q.push({newX, newY});
                        }
                        else if(grid[newX][newY] == 1)
                        {
                            return flips;
                        }
                    }
                }
                
            }
            flips++;
        }
        
        // for(auto vec : grid)
        // {
        //     for(auto it : vec)
        //     {
        //         cout<<it<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return -1;
    }
};