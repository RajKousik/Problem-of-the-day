class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        
        int count = 0;
        
        int col = strs[0].size();
        int row = strs.size();
        
        for(int c = 0; c < col; c++)
        {
            for(int r = 1; r < row; r++)
            {
                if(strs[r][c] < strs[r-1][c])
                {
                    count++;
                    break;
                }
            }
        }
        
        return count;
        
    }
};