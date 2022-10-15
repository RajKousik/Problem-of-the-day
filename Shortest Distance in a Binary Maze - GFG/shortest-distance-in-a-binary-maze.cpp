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
        
        //if it is within the boundary, and grid cell is 1, and not visited before
        // return true, else return false
        return x >= 0 and x < m and y >= 0 and y < n and grid[x][y] == 1 and vis[x][y] == 0;
    }
  
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
    
        // row and column
        int m = grid.size();
        int n = grid[0].size();
        
        //queue of pair for BFS
        queue<pair<int, int>> q;
        
        //push the source
        // q.push({source.first, source.second});
        q.push(source);
        
        
        //initially no moves made
        int moves = 0;
        //base codition for BFS function
        bool isPushed = false;
        
        //for moving in all the 4 directions
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {1, -1, 0, 0};
        
        //visited array to keep track of visited cells
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        // until the q is empty
        while(!q.empty())
        {
            int size = q.size();
            //isPushed is false, as we have pushed nothing as of time
            isPushed = false;
            
            while(size--)
            {
                auto node = q.front();
                q.pop();
                int x = node.first;
                int y = node.second;
                
                //if we found destination node, return the moves
                if(x== destination.first and y == destination.second)
                {
                    return moves;
                }
                
                //go in all 4 directions, and if valid, push to queue
                for(int dir=0; dir<4; dir++)
                {
                    int newX = x + dx[dir];
                    int newY = y + dy[dir];
                    
                    if(isSafe(newX, newY, grid, vis))
                    {
                        vis[newX][newY] = 1;    //mark it as visisted
                        q.push({newX, newY});   //push it to queue
                        isPushed = true;        //mark isPushed as true
                    }
                    
                }
                
            }
            //if we have pushed something in current iteration, make moves = moves + 1
            if(isPushed)
            {
                moves++;
            }   
            //no move is made, so queue will be empty, return -1
            else
            {
                return -1;
            }
        }
        
        //return -1
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