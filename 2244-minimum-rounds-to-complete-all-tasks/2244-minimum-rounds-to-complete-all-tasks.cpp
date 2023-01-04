class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        
        unordered_map<int, int> umap;
        
        for(auto it : tasks)
        {
            umap[it]++;
        }
        
        int count = 0;
        for(auto it : umap)
        {
            
            if(it.second == 1)
            {
                return -1;
            }
            
            if(it.second % 3 == 0)
            {
                count += (it.second/3);
            }
            else
            {
                count += (it.second/3 + 1);
            }
            
        }
        
        return count;
    }
};