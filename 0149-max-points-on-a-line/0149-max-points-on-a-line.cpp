class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        
        if(n == 1 or n == 2) return n;
        
        int ans = 2;
        for(int i=0; i<n; i++)
        {
            unordered_map<double, int> umap;
            for(int j=0; j<n; j++)
            {
                if(i != j)
                umap[atan2(points[j][1] - points[i][1], points[j][0] - points[i][0])]++;
                
            }
            
            for(auto it : umap)
            {
                ans = max(ans, it.second + 1);
            }
            
        }
        
        return ans;
        
    }
};