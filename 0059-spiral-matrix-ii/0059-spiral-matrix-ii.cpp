class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        
        vector<vector<int>> spiralMatrix(n, vector<int>(n, -1));
        
        int cnt = 1;
        int left = 0, right = n-1;
        int top = 0, bottom = n-1;
        
        while(cnt <= n * n)
        {
            
            for(int i=left ; cnt <= n * n and i<=right; i++)
            {
                spiralMatrix[top][i] = cnt;
                cnt++;
            }
            top++;
            
            for(int i=top; cnt <= n * n and i <= bottom; i++)
            {
                spiralMatrix[i][right] = cnt;
                cnt++;
            }
            right--;
            
            for(int i=right; cnt <= n * n and i>=left; i--)
            {
                spiralMatrix[bottom][i] = cnt;
                cnt++;
            }
            bottom--;
            
            for(int i=bottom; cnt<=n*n and i>=top; i--)
            {
                spiralMatrix[i][left] = cnt;
                cnt++;
            }
            left++;
            
        }
        
        return spiralMatrix;
        
        
    }
};