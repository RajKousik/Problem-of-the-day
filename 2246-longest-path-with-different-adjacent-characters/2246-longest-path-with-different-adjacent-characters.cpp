class Solution {
public:
    
    int dfs(int node, vector<vector<int>> &graph, string &s, int &longestPath)
    {
        
        int longestChain = 0;
        int secondLargestChain = 0;
        
        for(auto child : graph[node])
        {
            
            int longestChainFromChild = dfs(child, graph, s, longestPath);
            
            if(s[child] == s[node])
            {
                continue;
            }
            
            if(longestChainFromChild > longestChain)
            {
                secondLargestChain = longestChain;
                longestChain = longestChainFromChild;
            }
            else if(longestChainFromChild > secondLargestChain)
            {
                secondLargestChain = longestChainFromChild;
            }
            
        }
        
        longestPath = max(longestPath, longestChain + secondLargestChain + 1);
        
        return longestChain + 1;
        
        
        
    }
    
    
    int longestPath(vector<int>& parent, string s) {
        
        int n = parent.size();
        vector<vector<int>> graph(n);
        
        //creating the adjacency graph from the given parent array
        for(int i=1; i<n; i++)
        {
            graph[parent[i]].push_back(i);
        }
        
        int longestPath = 1;
        
        dfs(0, graph, s, longestPath);
        
        return longestPath;
        
    }
};