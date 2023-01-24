class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        
        int n =  board.size();
        
        vector<pair<int, int>> cells(n*n + 1);
        
        int label = 1;
        
        
        vector<int> columns(n);
        
        iota(columns.begin(), columns.end(), 0);
        
        for(int row = n-1; row >=0; row--)
        {
            for(int col : columns)
            {
                cells[label++] = {row, col};
            }
            reverse(columns.begin(), columns.end());
        }
        
        queue<int> q;
        vector<int> dist(n*n+1, -1);
        q.push(1);
        dist[1] = 0;
        
        while(!q.empty())
        {
            int currentNode = q.front();
            q.pop();
            
            for(int next = currentNode + 1; next <= min(currentNode + 6, n*n); next++)
            {
                auto it = cells[next];
                
                int destination;
                if(board[it.first][it.second] != -1)
                {
                    destination = board[it.first][it.second];
                }
                else
                {
                    destination = next;
                }
                
                if(dist[destination] == -1)
                {
                    dist[destination] = dist[currentNode] + 1;
                    q.push(destination);
                }
                
            }
        }
        
        return dist[n*n];
    }
};