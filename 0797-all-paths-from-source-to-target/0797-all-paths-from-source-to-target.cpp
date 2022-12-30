class Solution {
public:
    
    void dfs(int src, int dest, vector<vector<int>> &graph, vector<int> &path, vector<vector<int>> &ans)
    {
        if(src == dest)
        {
            path.push_back(src);
            ans.push_back(path);
            return;
        }
            
        path.push_back(src);
        for(auto it : graph[src])
        {
            // path.push_back(it);
            dfs(it, dest, graph, path, ans);
            path.pop_back();
        }
          
    }
    
    
    
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>> ans;
        
        vector<int> path;
        
        int n = graph.size();
        
        dfs(0, n-1, graph, path, ans);
        
        return ans;
        
    }
};