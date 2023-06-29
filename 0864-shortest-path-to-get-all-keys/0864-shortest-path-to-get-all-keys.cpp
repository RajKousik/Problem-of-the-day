class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid)
    {
        
        int m = grid.size();
        int n = grid[0].size();
        
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {1, -1, 0, 0};
        
        int noOfKeys = 0;
        int startX = -1, startY = -1;
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] >= 'a' and grid[i][j] <= 'z')
                {
                    noOfKeys++;
                    
                }
                else if(grid[i][j] == '@')
                {
                    startX = i, startY = j;
                }
            }
        }
        
        // cout<<startX<<startY<<endl;
        
        //1 -> key not found, 0 -> key found
        int keyMask = (1 << noOfKeys) - 1;
        
        queue<pair<int, pair<int, int>>> q;
        map<pair<int, int>, set<int> > visited;
        
        q.push({keyMask, {startX, startY}});
        visited[{startX, startY}].insert(keyMask);
        
        
        int noOfMoves = 0;
        while(!q.empty())
        {
            int size = q.size();
            
            while(size--)
            {
                
                auto node = q.front();
                q.pop();
                
                int row = node.second.first; 
                int col = node.second.second;
                keyMask = node.first;
                
                // cout<<keyMask<<endl;
                
                if(grid[row][col] >= 'a' and grid[row][col] <= 'z')
                {
                    if(keyMask & (1 << (grid[row][col] - 'a')))
                    {
                        keyMask -= (1 << (grid[row][col] - 'a'));
                    }
                }
                
                
                if(keyMask == 0)
                {
                    return noOfMoves;
                }
                
                
                
                for(int dir = 0; dir < 4 ; dir++)
                {
                    
                    int newX = row + dx[dir];
                    int newY = col + dy[dir];
                    
                    if(newX < 0 or newX >= m or newY < 0 or newY >= n)
                    {
                        continue;
                    }
                    
                    if(grid[newX][newY] == '#')
                    {
                        continue;
                    }
                    
                    if(grid[newX][newY] >= 'A' and grid[newX][newY] <= 'Z' and
                        (keyMask & (1 << (grid[newX][newY] - 'A'))) )
                    {
                        continue;
                    }
                    
                    pair<int, int> temp = make_pair(newX, newY);
                    if(visited[temp].find(keyMask) == visited[temp].end())
                    {
                        q.push({keyMask, {newX, newY}});
                        visited[temp].insert(keyMask);
                    }
                    
                }
                
            }
            noOfMoves++;
        }
        
        return -1;
        
    }
};