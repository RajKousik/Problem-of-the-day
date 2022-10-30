class Solution {
public:

    int shortestPath(vector<vector<int>>& grid, int k)
    {
        
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), -1));
        
        queue<vector<int>> q;
        
        q.push({0, 0, 0, k});
        
        while(!q.empty())
        {
            
            auto it = q.front();
            int x = it[0];
            int y = it[1];
            q.pop();
            
            if(x < 0 or y < 0 or x>=grid.size() or y>=grid[0].size())
            {
                continue;
            }
            
            if(x == grid.size() -1 and y == grid[0].size() -1 )
            {
                return it[2];
            }
            
            if(grid[x][y] == 1)
            {
                if(it[3] > 0)
                {
                    it[3]--;
                }
                else
                {
                    continue;
                }
            }
            
            if(vis[x][y] != -1 and vis[x][y] >= it[3])
            {
                continue;
            }
            
            vis[x][y] = it[3];
            
            q.push({x+1, y, it[2]+1, it[3]});
            q.push({x, y+1, it[2]+1, it[3]});
            q.push({x-1, y, it[2]+1, it[3]});
            q.push({x, y-1, it[2]+1, it[3]});
            
        }
        return -1;
        
    }
};