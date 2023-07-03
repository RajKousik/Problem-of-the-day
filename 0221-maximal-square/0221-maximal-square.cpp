class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int res = 0, m=matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==0 or j==0 or matrix[i][j] == '0')
                {
                    dp[i][j] = matrix[i][j] - '0';
                }
                else
                {
                    dp[i][j] = min({dp[i-1][j-1], dp[i][j-1], dp[i-1][j]}) + 1;
                }
                res = max(res, dp[i][j]);
            }
        }
        
        return res * res;
    }
};