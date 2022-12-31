class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int i = m - 1;
        int j = 0;
        
        while(i >=0 and j < n)
        {
            if(matrix[i][j] == target)
            {
                return 1;
            }
            else if(matrix[i][j] < target)
            {
                j++;
            }
            else
            {
                i--;
            }
        }
        return 0;
        
    }
};