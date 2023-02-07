class Solution {
public:
    int totalFruit(vector<int>& fruits) 
    {
        
        int left = 0;
        int right = 0;
        
        int n = fruits.size();
        
        unordered_map<int, int> umap;
        
        int maxLen = 0;
        
        while(right < n)
        {
            
            umap[fruits[right]]++;
            
            while(umap.size() > 2)
            {
                umap[fruits[left]]--;
                if(umap[fruits[left]] == 0)
                {
                    umap.erase(fruits[left]);
                }
                left++;
            }
            
            
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        
        return maxLen;
    }
};