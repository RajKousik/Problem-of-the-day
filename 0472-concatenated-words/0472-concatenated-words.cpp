class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
        unordered_set<string> st(words.begin(),words.end());
        
        vector<string> ans;
        
        for(auto word : words)
        {
            int n = word.size();
            vector<bool> dp(n+1);
            
            dp[0] = true;
            
            for(int i=1; i<=n; i++)
            {
                for(int j=(i==n) ? 1 : 0; !dp[i] and j < i; j++)
                {
                    dp[i] = dp[j] and st.count(word.substr(j, i-j));
                }
            }
            if(dp[n])
            {
                ans.push_back(word);
            }
        }
        return ans;
    }
};