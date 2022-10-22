class Solution {
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> umap;
        
        int distinct = 0;
        // vector<int> freq(256, 0);
        
        
        for(int i=0; i<t.size(); i++)
        {
            if(umap[t[i]] == 0)
            {
                distinct++;
            }
            umap[t[i]]++;
        }
        
        int ans = INT_MAX;
        int i=0;
        int j=0;
        int start = 0;
        
        while(j < s.size())
        {
            umap[s[j]]--;
            
            if(umap[s[j]] == 0)
            {
                distinct--;
            }
            
            if(distinct == 0)
            {
                while(distinct == 0)
                {
                    if(ans > (j - i + 1))
                    {
                        ans = j - i + 1;
                        start = i;
                    }
                    
                    umap[s[i]]++;
                    
                    if(umap[s[i]] == 1)
                    {
                        distinct++;
                    }

                    i++;
                }
            }
            
            j++;
        }
        
        if(ans == INT_MAX)
        {
            return "";
        }
        
        return s.substr(start, ans);
        
    }
};