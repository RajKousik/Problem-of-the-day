class Solution {
public:
    
    int helper(int node, int parent, vector<int> graph[], vector<bool>& hasApple)
    {

        int totalTime = 0;
        int childTime = 0;
        
        for(auto it : graph[node])
        {
            if(it == parent) continue;
            
            childTime = helper(it, node, graph, hasApple);
            
            if(childTime or hasApple[it])
            {
                totalTime += (childTime + 2);
            }
            
        }
        
        return totalTime;
        
        
    }
    
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        
        vector<int> graph[n];
        
        for(auto it : edges)
        {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        
        return helper(0, -1, graph, hasApple);
        
    }
};