//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class DSU
{
private:
    vector<int> parent;
    vector<int> size;
    
public:


    DSU(int n)
    {
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0; i<=n; i++)
        {
            parent[i] = i;
            size[i] = 0;
        }
    }
    
    int findParent(int node)
    {
        if(parent[node] == node)
        {
            return node;
        }
        
        return parent[node] = findParent(parent[node]);
    }
    
    void unionBySize(int u, int v)
    {
        
        int uParent = findParent(u);
        int vParent = findParent(v);
        
        if(uParent == vParent)
        {
            return;
        }
        
        if(size[uParent] < size[vParent])
        {
            parent[uParent] = vParent;
            size[vParent] += size[uParent];
        }
        else
        {
            parent[vParent] = uParent;
            size[uParent] += size[vParent];
        }
        
    }
    
};



class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        
        DSU dsu(n*m+1);
        
        vector<vector<int>> grid(n, vector<int>(m, 0));
        
        vector<int> ans;
        int cnt = 0;
        
        for(auto it : operators)
        {
            
            int x = it[0];
            int y = it[1];
            
            if(grid[x][y] == 1)
            {
                ans.push_back(cnt);
                continue;
            }
            
            cnt++;
            grid[x][y] = 1;
            
            int currIndex = (x * m) + (y+1);
            
            int dx[4] = {0, 0, -1, +1};
            int dy[4] = {+1, -1, 0, 0};
            
            for(int dir = 0; dir< 4; dir++)
            {
                int newX = x + dx[dir];
                int newY = y + dy[dir];
                
                int newIndex = (newX * m) + (newY + 1);
                
                if(newX >= 0 and newX < n and newY>=0 and newY < m and grid[newX][newY] == 1 and dsu.findParent(currIndex) != dsu.findParent(newIndex))
                {
                    cnt--;
                    dsu.unionBySize(currIndex, newIndex);
                }
            }
            
            ans.push_back(cnt);
        
        }
        
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends