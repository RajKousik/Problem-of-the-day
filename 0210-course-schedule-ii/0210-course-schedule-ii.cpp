class Solution {
public:
    
    //just apply topo sort
    // since topological order can only be applied for DAG(Directed Acyclic Graph)
    // if we apply topo function and got the correct ordering of the topo sort, then this is not a cyclic grpah, so we can finish all the tasks
    // if we are not getting correct ordering of the topo sort, then it must be a cyclic graph, so we cannot finish all the tasks
    
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<int> inDegree(V, 0), adj[V], ans;
        for(auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0; i<V; i++) {
            for(auto it : adj[i])
                inDegree[it]++;
        }
        queue<int> q;
        for(int i=0; i<V; i++) {
            if(inDegree[i] == 0)
                q.push(i);
        }
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : adj[node]) {
                inDegree[it]--;
                if(inDegree[it] == 0)
                    q.push(it);
            }   
        }
        if(ans.size() != V) return {};
        return ans;
    }
};