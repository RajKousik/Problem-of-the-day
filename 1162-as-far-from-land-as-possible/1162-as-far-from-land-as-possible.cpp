class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) 
    {
        
        
        queue<pair<int, int>> q;
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j])
                {
                    vis[i][j] = grid[i][j];
                    q.push({i, j});
                }
            }
        }
        
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {1, -1, 0, 0};
        
        int distance = -1;
        
        while(!q.empty())
        {
            int size = q.size();
            
            while(size--)
            {
                
                auto node = q.front();
                q.pop();
                
                int x = node.first;
                int y = node.second;
                
                for(int k=0; k<4; k++)
                {
                    int nextX = x + dx[k];
                    int nextY = y + dy[k];
                    
                    if(nextX >= 0 and nextX < m and nextY >= 0 and nextY < n
                      and !vis[nextX][nextY])
                    {
                        vis[nextX][nextY] = 1;
                        q.push({nextX, nextY});
                    }
                    
                }
                
                
            }
            
            distance++;
            
        }
        
        return distance == 0 ? -1 : distance; 
        
    }
};