class Solution {
public:
    

    

    bool isPossible(int row, int col, vector<vector<char>> &sudoku, char ch, vector<vector<int>> &rowHash, vector<vector<int>> &colHash, vector<vector<vector<int>>> &squareHash)
    {
        if(rowHash[row][ch-'0'] == 1) return false;
        if(colHash[col][ch-'0'] == 1) return false;
        if(squareHash[row/3][col/3][ch-'0'] == 1) return false;
        return true;
    }

    bool solve(int row, int col, vector<vector<char>> &sudoku, vector<vector<int>> &rowHash, vector<vector<int>> &colHash, vector<vector<vector<int>>> &squareHash)
    {
        if(row == 9)
        {
            return true;
        }
        if(col == 9)
        {
            return solve(row+1, 0, sudoku, rowHash, colHash, squareHash);
        }
        if(sudoku[row][col] != '.')
        {
            return solve(row, col+1, sudoku, rowHash, colHash, squareHash);
        }

        for(char ch='1'; ch<='9'; ch++)
        {

            if(isPossible(row, col, sudoku, ch, rowHash, colHash, squareHash))
            {
                sudoku[row][col] = ch;
                rowHash[row][ch-'0'] = 1;
                colHash[col][ch-'0'] = 1;
                squareHash[row/3][col/3][ch-'0'] = 1;

                if(solve(row, col+1, sudoku, rowHash, colHash, squareHash))
                    return true;

                sudoku[row][col] = '.';
                rowHash[row][ch-'0'] = 0;
                colHash[col][ch-'0'] = 0;
                squareHash[row/3][col/3][ch-'0'] = 0;
            }
        }
        return false;
    }

    
    void solveSudoku(vector<vector<char>>& sudoku) 
    {
        vector<vector<int>> rowHash(9, vector<int>(10, 0));
        vector<vector<int>> colHash(9, vector<int>(10, 0));
        vector<vector<vector<int>>> squareHash(3, vector<vector<int>>(3, vector<int>(10, 0)));
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char ch = sudoku[r][c];
                if (ch != '.') {
                    rowHash[r][ch-'0'] = 1;
                    colHash[c][ch-'0'] = 1;
                    squareHash[r/3][c/3][ch-'0'] = 1;
                } 
            }
        }
        solve(0, 0, sudoku, rowHash, colHash, squareHash);
    }
};