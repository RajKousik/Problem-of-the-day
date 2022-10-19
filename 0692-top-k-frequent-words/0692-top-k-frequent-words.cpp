class Solution {
    
    
    
public:
    
    struct comp
    {
        bool operator() (pair<string, int> a, pair<string, int> b)
        {
            if(a.second == b.second)
            {
                return a.first < b.first;
            }
            
            return a.second > b.second;
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k)
    {
        
        unordered_map<string, int> umap;
        
        for(auto w : words)
        {
            umap[w]++;
        }
        
        priority_queue< pair<string, int>, vector<pair<string, int>>, comp > pq;
        
        for(auto it : umap)
        {
            pq.push({it.first, it.second});
            if(pq.size() > k)
            {
                pq.pop();
            }
        }
        
        vector<string> ans;
        
        while(!pq.empty())
        {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
        
    }
};