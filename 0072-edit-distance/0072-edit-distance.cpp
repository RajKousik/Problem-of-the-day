class Solution 
{
private:
    
    int helper(string word1, string word2, int word1Ind, int word2Ind, vector<vector<int>> &dp)
    {
        
        if(word1Ind == 0)
        {
            return word2Ind;
        }
        if(word2Ind == 0)
        {
            return word1Ind;
        }
        
        if(dp[word1Ind][word2Ind] != -1)
        {
            return dp[word1Ind][word2Ind];
        }
        
        if(word1[word1Ind-1] == word2[word2Ind-1])
        {
            return dp[word1Ind][word2Ind] = helper(word1, word2, word1Ind - 1, word2Ind - 1, dp);
        }
        else
        {
            int insertOp = helper(word1, word2, word1Ind, word2Ind - 1, dp);
            int deleteOp = helper(word1, word2, word1Ind - 1, word2Ind, dp);
            int replaceOp = helper(word1, word2, word1Ind - 1, word2Ind - 1, dp);
            return dp[word1Ind][word2Ind] = min({insertOp, deleteOp, replaceOp}) + 1;
        }
        
    }
    
public:
    int minDistance(string word1, string word2) 
    {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, -1));
        return helper(word1, word2, word1.size(), word2.size(), dp);    
    }
};