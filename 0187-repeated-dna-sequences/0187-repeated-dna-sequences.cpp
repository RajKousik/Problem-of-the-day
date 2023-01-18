class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        unordered_map<string, int> umap;
        vector<string> res;
        
        if (s.size() < 10) return res;
        
        for (int i=0; i<s.size()-9; i++)
            umap[s.substr(i, 10)]++;
        
        for (auto a:umap)
            if (a.second > 1)
                res.push_back(a.first);
        
        return res;
        
    }
};