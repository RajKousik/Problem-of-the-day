class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        if(numRows == 1)
        {
            return {{1}};
        }
        
        vector<vector<int>> ans(numRows, vector<int>(numRows));
        // ans.push_back({1});
        
        for(int i=0; i<numRows; i++)
        {
            ans[i].resize(i+1);
            ans[i][0] = 1;
            ans[i][i] = 1;
            
            for(int j=1; j<i; j++)
            {
                ans[i][j] = ans[i-1][j] + ans[i-1][j-1];
            }
            
            
        }
        
        
        return ans;
        
    }
};