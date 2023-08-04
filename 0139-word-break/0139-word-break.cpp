class Solution {
    
    bool helper(int index, string s, unordered_set<string> &st, vector<int> &dp)
    {
        if(index == s.size())
        {
            return true;
        }
        
        if(dp[index] != -1)
        {
            return dp[index];
        }
        
        for(int i=index; i<s.size(); i++)
        {
            string word = s.substr(index, i-index+1);
            if(st.find(word) != st.end())
            {
                if(helper(i+1, s, st, dp))
                {
                    return dp[index] = true;
                }
            }
        }
        return dp[index] = false;
    }
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.size();
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<int> dp(n, -1);
        return helper(0, s, st, dp);
        
    }
};