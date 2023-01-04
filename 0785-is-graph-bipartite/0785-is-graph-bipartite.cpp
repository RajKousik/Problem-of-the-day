class Solution {
public:
    
    bool dfs(int node, int currColor, vector<vector<int>>& graph, vector<int> &color)
    {
        
        color[node] = currColor; 
        
        for(auto it : graph[node])
        {
            if(color[it] == -1)
            {
                if(dfs(it,  1- currColor, graph, color) == false)
                {
                    return false;
                }
            }
            else if(color[it] == currColor)
            {
                return false;
            }
        }
        
        return true;
        
    }
    
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        
        vector<int> color(n, -1);
        
        for(int i=0; i<n; i++)
        {
            if(color[i] == -1)
            {
                if(dfs(i, 0, graph, color) == false)
                {
                    for(auto it : color) cout<<it<<endl;
                    return false;
                }
            }
        }
        
        
        
        return true;
        
        
    }
};