//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int isSafe(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &vis)
    {
        int m = grid.size();
        int n = grid[0].size();
        
        return x >= 0 and x < m and y >= 0 and y < n and grid[x][y] == 1 and vis[x][y] == 0;
    }
  
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        
        // if(source.first == destination.first and source.second == destination.second)
        // {
        //     return 0;
        // }
        
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int, int>> q;
        q.push({source.first, source.second});
        
        int moves = 0;
        bool isPushed = false;
        
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {1, -1, 0, 0};
        
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        while(!q.empty())
        {
            int size = q.size();
            isPushed = false;
            while(size--)
            {
                auto node = q.front();
                q.pop();
                int x = node.first;
                int y = node.second;
                
                if(x== destination.first and y == destination.second)
                {
                    return moves;
                }
                
                for(int dir=0; dir<4; dir++)
                {
                    int newX = x + dx[dir];
                    int newY = y + dy[dir];
                    
                    if(isSafe(newX, newY, grid, vis))
                    {
                        // cout<<newX<<" "<<newY<<endl;
                        vis[newX][newY] = 1;
                        q.push({newX, newY});
                        isPushed = true;
                    }
                    
                }
                
            }
            if(isPushed)
            {
                moves++;
            }
            else
            {
                return -1;
            }
        }
        
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends