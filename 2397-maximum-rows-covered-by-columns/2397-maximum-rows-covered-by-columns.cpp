class Solution 
{
private:
    
    int countBits(int num)
    {
        int count = 0;
        while(num)
        {
            num = num & (num-1);
            count++;
        }
        return count;
    }
    
public:
    int maximumRows(vector<vector<int>>& matrix, int numSelect)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int totalCombo = 1 << n;
        int ans = 0;
        
        for(int mask = 0; mask < totalCombo; mask++)
        {
            if(countBits(mask) == numSelect)
            {
                cout<<mask<<" ";
                int rowsCovered = 0;
                for(int i=0; i<m; i++)
                {
                    bool canTake = true;
                    for(int j=0; j<n; j++)
                    {
                        if(matrix[i][j] == 1 and ( ( (mask >> j) & 1) == 0))
                        {
                            canTake = false;
                            break;
                        }
                    }
                    if(canTake)
                    {
                        rowsCovered++;
                    }
                }
                ans = max(ans, rowsCovered);
            }
        }
        return ans;
    }
};