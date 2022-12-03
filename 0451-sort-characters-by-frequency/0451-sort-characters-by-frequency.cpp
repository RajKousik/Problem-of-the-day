class Solution {
public:
    string frequencySort(string s) 
    {
        unordered_map<char, int> umap;
        priority_queue<pair<int, char>> pq;
        
        for(auto it : s)
        {
            umap[it]++;
        }
        
        for(auto it : umap)
        {
            pq.push({it.second, it.first});
        }
        
        string ans = "";
        
        while(!pq.empty())
        {
            auto node = pq.top();
            pq.pop();
            
            int freq = node.first;
            char ch = node.second;
            
            // for(int i=0; i<freq; i++)
            // {
            //     ans.push_back(ch);
            // }
            
            ans += string(freq, ch);
            
        }
        
        return ans;
        
        
    }
};