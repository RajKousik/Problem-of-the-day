class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        
        unordered_map<string, vector<string>> umap;
        
        for(auto s : strs)
        {
            string t = s;
            sort(t.begin(), t.end());
            umap[t].push_back(s);
        }
        
        vector<vector<string>> ans;
        
        for(auto it : umap)
        {
            ans.push_back(it.second);
        }
        
        return ans;
        
    }
};