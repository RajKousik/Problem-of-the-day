class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        int V = numCourses;
        
        vector<int> inDegree(V, 0);
        
        vector<int> adj[V];
        
        for(auto it : prerequisites)
        {
            adj[it[0]].push_back(it[1]);
        }
        
        
        for(int i=0; i<V; i++)
        {
            for(auto it : adj[i])
            {
                inDegree[it]++;
            }
        }
        
        queue<int> q;
        
        for(int i=0; i<V; i++)
        {
            if(inDegree[i] == 0)
            {
                q.push(i);
            }
        }
        
        vector<int> ans;
        while(!q.empty())
        {
            
            auto node = q.front();
            q.pop();
            
            ans.push_back(node);
            
            for(auto it : adj[node])
            {
                inDegree[it]--;
                if(inDegree[it] == 0)
                {
                    q.push(it);
                }
            }
            
            
        }
        
        return ans.size() == V;
    }
};