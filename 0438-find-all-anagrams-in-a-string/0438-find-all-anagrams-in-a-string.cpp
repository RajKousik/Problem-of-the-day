class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        int sLen = s.size();
        int pLen = p.size();
        
        if(pLen > sLen)
        {
            return {};
        }
        
        vector<int> freq(26, 0);
        vector<int> window(26, 0);
        
        for(int i=0; i<pLen; i++)
        {
            freq[p[i]-'a']++;
            window[s[i]-'a']++;
        }
        
        vector<int> ans;
        
        if(freq == window)
        {
            ans.push_back(0);
        }
        
        for(int i=pLen; i<sLen; i++)
        {
            window[s[i]-'a']++;
            window[s[i-pLen]-'a']--;
            
            if(freq == window)
            {
                ans.push_back(i - pLen + 1);
            }
        }
        
        return ans;
        
        
    }
};