class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        int i=0, j=0;
        
        int m = word1.size();
        int n = word2.size();
        
        string ans = "";
        
        while(i < m or j < n)
        {
            if(i < m)
            {
                ans += word1[i++];
            }
            if(j < n)
            {
                ans += word2[j++];
            }
        }
        
        return ans;
        
    }
};