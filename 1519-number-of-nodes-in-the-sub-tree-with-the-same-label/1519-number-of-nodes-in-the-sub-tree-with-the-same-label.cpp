class Solution {
public:
    
    
    vector<int> dfs(int node, int parent, vector<int> adj[], string &labels, vector<int> &ans)
    {
        
        vector<int> nodeCount(26);
        
        nodeCount[labels[node] - 'a'] = 1;
        
        for(auto &it : adj[node])
        {
            if(it == parent) continue;
            
            vector<int> childCount = dfs(it, node, adj, labels, ans);
            
            for(int i=0; i<26; i++)
            {
                nodeCount[i] += childCount[i];
            }
            
        }
        
        ans[node] = nodeCount[labels[node] - 'a'];
        
        return nodeCount;
        
    }
    
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        
        vector<int> adj[n];
        
        for(auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> ans(n);
        
        dfs(0, -1, adj, labels, ans);
        
        return ans;
        
    }
};