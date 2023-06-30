class Solution {
private:
    
    bool isPossible(vector<vector<int>> &cells, int row, int col, int day)
    {
        
        vector<vector<int>> grid(row, vector<int>(col, 0));
        
        for(int i=0; i<day; i++)
        {
            grid[cells[i][0]-1][cells[i][1]-1] = 1;
        }
        
        queue<pair<int, int>> q;
        
        for(int i=0; i<col; i++)
        {
            if(grid[0][i] == 0)
            {
                q.push({0, i});
            }
            grid[0][i] = -1;
        }
        
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            
            int x = node.first;
            int y = node.second;
            
            if(x == row-1)
            {
                return true;
            }
            
            
            
            for(int dir = 0; dir < 4; dir++)
            {
                int newX = x + dx[dir];
                int newY = y + dy[dir];
                
                if(newX >= 0 and newY >= 0 and newX < row and newY < col 
                  and grid[newX][newY] == 0)
                {
                    q.push({newX, newY});
                    grid[newX][newY] = -1;
                }
                
            }
            
        }
        
        return false;
        
    }

public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        
            //Binary Search on answer + BFS
        
        int low = 1, high = row * col;
        int ans = -1;
        
        while(low <= high)
        {
            int mid = low + (high - low)/2;

            if(isPossible(cells, row, col, mid))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }
};