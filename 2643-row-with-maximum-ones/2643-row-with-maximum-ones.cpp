class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        
        int maxCount = 0, row = 0;
        for(int i=0; i<mat.size(); i++)
        {
            int count = 0;
            for(int j=0; j<mat[0].size(); j++)
            {
                if(mat[i][j] == 1)
                {
                    count++;
                }
            }
            if(count > maxCount)
            {
                maxCount = count;
                row = i;
            }
        }        
        return {row, maxCount};
    }
};