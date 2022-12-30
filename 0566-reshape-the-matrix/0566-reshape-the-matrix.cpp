class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        
        
        int m = mat.size();
        int n = mat[0].size();
        
        if((m*n) != (r*c))
        {
            return mat;
        }
        
        vector<int> oneD(m*n);
        
        // cout<<m<<n<<endl;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                oneD[n*i + j] = mat[i][j];
                // cout<<i<<" "<<j<<endl;
            }
        }
        
        // for(auto it : oneD) cout<<it<<" ";
        
        vector<vector<int>> ans(r, vector<int>(c));
        
        for(int i=0; i<m*n; i++)
        {
            ans[i/c][i%c] = oneD[i];
        }
        
        return ans;
        
    }
};