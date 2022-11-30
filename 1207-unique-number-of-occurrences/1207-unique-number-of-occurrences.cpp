class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        unordered_map<int, int> umap;
        
        for(auto it : arr) umap[it]++;
        
        unordered_set<int> st;
        for(auto it : umap) st.insert(it.second);
        
        return st.size() == umap.size();
        
    }
};