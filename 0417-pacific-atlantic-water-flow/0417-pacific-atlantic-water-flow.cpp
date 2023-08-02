class Solution {
    
    void bfs(vector<vector<bool>> &ocean, queue<pair<int, int>> &queue, vector<vector<int>>& heights)
    {
        
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {1, -1, 0, 0};
        
        while(!queue.empty())
        {
            auto node = queue.front();
            queue.pop();
            
            int x = node.first;
            int y = node.second;
            
            for(int dir=0; dir<4; dir++)
            {
                int newX = x + dx[dir];
                int newY = y + dy[dir];
                
                if(newX >=0 and newX < heights.size() and newY >= 0 and newY < heights[0].size() and heights[newX][newY] >= heights[x][y] and ocean[newX][newY] == false)
                {
                    ocean[newX][newY] = true;
                    queue.push({newX, newY});
                }
                
            }
            
        }
        
    }
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<bool>> pacificOcean(m, vector<bool>(n, false));
        queue<pair<int, int>> pacificQueue;
        
        vector<vector<bool>> atlanticOcean(m, vector<bool>(n, false));
        queue<pair<int, int>> atlanticQueue;
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i == 0 or j == 0)
                {
                    pacificOcean[i][j] = true;
                    pacificQueue.push({i, j});
                }
                if(i == m-1 or j == n-1)
                {
                    atlanticOcean[i][j] = true;
                    atlanticQueue.push({i, j});
                }
            }
        }
        
        bfs(pacificOcean, pacificQueue, heights);
        bfs(atlanticOcean, atlanticQueue, heights);
        
        vector<vector<int>> ans;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(pacificOcean[i][j] == true and atlanticOcean[i][j] == true)
                {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};