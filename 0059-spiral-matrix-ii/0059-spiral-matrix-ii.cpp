class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        
        vector<vector<int>> ans(n, vector<int>(n, -1));
        
        int l = 0, r = n - 1;
        int t = 0, b = n - 1;
        
        int cnt = 1;
        
        while(cnt <= n*n)
        {
            for(int i=l; cnt <= n*n and i<=r; i++)
            {
                ans[t][i] = cnt;
                cnt++;
            }
            t++;
            
            for(int i=t; cnt <= n*n and i<=b; i++)
            {
                ans[i][r] = cnt;
                cnt++;
            }
            r--;
            
            for(int i=r; cnt <= n*n and i>=l; i--)
            {
                ans[b][i] = cnt;
                cnt++;
            }
            b--;
            
            for(int i=b; cnt <= n*n and i>=t; i--)
            {
                ans[i][l] = cnt;
                cnt++;
            }
            l++;
            // break;
        }
        
        return ans;
    
    }
};