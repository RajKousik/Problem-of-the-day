class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) 
    {
        
        vector<vector<int>> vis(rows, vector<int>(cols, false));
        vis[rCenter][cCenter] = true;
        
        
        queue<pair<int, int>> q;
        q.push({rCenter, cCenter});
        
        vector<vector<int>> ans;
        ans.push_back({rCenter, cCenter});
        
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            
            int x = node.first;
            int y = node.second;
            
            for(int dir=0; dir<4; dir++)
            {
                int newX = x + dx[dir];
                int newY = y + dy[dir];
                
                if(newX >=0 and newY >=0 and newX < rows and newY <cols and !vis[newX][newY])
                {
                    q.push({newX, newY});
                    ans.push_back({newX, newY});
                    vis[newX][newY] = true;
                }
            }
            
            
        }
        
        return ans;
        
        
    }
};