class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        unordered_map<int, int> umap;
        
        for(auto it : arr) umap[it]++;
        
        unordered_set<int> st;
        
        // for(auto it : umap) st.insert(it.second);
        // return st.size() == umap.size();
        
        //insteading of above two lines
        
        for(auto it : umap)
        {
            if((st.insert(it.second)).second == false)
            {
                return false;
            }
        }
        
        return true;
    }
};