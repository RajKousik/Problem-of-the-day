class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        
        vector<int> ans;
        
        vector<int> count(n);
        
        for(auto it : edges)
        {
            count[it[1]]++;
        }
        
        for(int i=0; i<n; i++)
        {
            if(count[i] == 0)
            {
                ans.push_back(i);
            }
        }
        
        return ans;
        
    }
};