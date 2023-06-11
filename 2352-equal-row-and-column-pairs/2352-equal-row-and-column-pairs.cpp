class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        
        map<vector<int>, int> umap;
        
        for(auto &row : grid)
        {
            umap[row]++;
        }
        
        for(int i=0; i<n; i++)
        {
            vector<int> temp;
            for(int j=0; j<n; j++)
            {
                temp.push_back(grid[j][i]);
            }
            
            ans += umap[temp];
        }
        return ans;
        
    }
};