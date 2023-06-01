class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        
        if(grid[0][0] != 0) return -1;
        
        int n = grid.size();
        queue< pair< pair<int, int>, int> > q;
        vector<vector<bool>> vis(n, vector<bool> (n, false));
        
        q.push({{0, 0}, 1});
        vis[0][0] = true;
        
        int dx[8] = {1, -1, 0, 0, 1, -1, -1, 1};
        int dy[8] = {0, 0, 1, -1, -1, 1, -1, 1};
        
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            
            int x = node.first.first;
            int y = node.first.second;
            int steps = node.second;
            
            cout<<x<<" "<<y<<endl;
            
            if(x == n-1 and y == n-1)
            {
                return steps;
            }
            
            for(int dir=0; dir<8; dir++)
            {
                int newX = x + dx[dir];
                int newY = y + dy[dir];
                
                if(newX >= 0 and newY >= 0 and newX < n and newY < n 
                  and grid[newX][newY] == 0 and vis[newX][newY] == false)
                {
                    q.push({{newX, newY}, steps + 1});
                    vis[newX][newY] = true;
                }
            }
            
        }
        
        return -1;
        
    }
};