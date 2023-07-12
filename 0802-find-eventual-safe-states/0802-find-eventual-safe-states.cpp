class Solution {
public:
    
    bool dfs(int node, vector<vector<int>>& adj, vector<bool> &isVisited, vector<bool> &isPathVisited)
    {
        isVisited[node]= true;
        isPathVisited[node] = true;
        
        for(auto adjacentNode : adj[node])
        {
            if(isVisited[adjacentNode] == false)
            {
                if(dfs(adjacentNode, adj, isVisited, isPathVisited))
                    return true;
            }
            else if(isPathVisited[adjacentNode] == true)
            {
                return true;
            }
                
        }
        
        isPathVisited[node] = false;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        //find the nodes which forms a cycle, other than these nodes
        //all other nodes are safe nodes
        
        int n = graph.size();
        
        vector<vector<int>> adj(n);
        
        for(int i=0; i<n; i++)
        {
            for(auto node : graph[i])
            {
                adj[i].push_back(node);
            }
        }
        
        vector<bool> isVisited(n, false);
        vector<bool> isPathVisited(n, false);
        for(int i=0; i<n; i++)
        {
            if(isVisited[i] == false)
            {
                dfs(i, adj, isVisited, isPathVisited);
            }
        }
        
        vector<int> safeNodes;
        for(int i=0; i<n; i++)
        {
            // cout<<i<<" "<<isVi
            if(isPathVisited[i] == false)
            {
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
        
    }
};