class Solution {
public:
    
    bool dfs(int i, int j, int index, vector<vector<char>>& board, string word)
    {
        
        if(index == word.size())
            return true;
        
        if(i < 0 or i>=board.size() or j < 0 or j>=board[0].size() or board[i][j] != word[index])
        {
            return false;
        }
        
        board[i][j] = '.';
        
        bool ans = dfs(i+1, j, index+1, board, word) or dfs(i-1, j, index+1, board, word) or dfs(i, j+1, index+1, board, word) or dfs(i, j-1, index+1, board, word);
        
        board[i][j] = word[index];
        
        return ans;
        
    }
    
    bool exist(vector<vector<char>>& board, string word) 
    {
        
        int r = board.size();
        int c = board[0].size();
        
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(board[i][j] == word[0])
                {
                    if(dfs(i, j, 0, board, word))
                    {
                        
                        return true;
                    }
                }
            }
        }
        
        return false;
        
    }
};