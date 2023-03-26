class Solution {
public:
    int longestCycle(vector<int>& edges) 
    {
        
        int n = edges.size();
        vector<bool> vis(n, false);
        vector<int> indegree(n);
        
        for(auto edge : edges)
        {
            if(edge != -1)
            {
                indegree[edge]++;
            }
        }
        
        queue<int> q;
        for(int i=0; i<n; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            vis[node] = true;
            int neigh = edges[node];
            
            if(neigh != -1)
            {
                indegree[neigh]--;
                if(indegree[neigh] == 0)
                {
                    q.push(neigh);
                }
            }
                  
        }
        
        int answer = -1;
        
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                int noOfEdges = 1;
                int neighbor = edges[i];
                vis[i] = true;
                
                while(neighbor != i)
                {
                    noOfEdges++;
                    neighbor = edges[neighbor];
                    vis[neighbor] = true;
                }
                answer = max(answer, noOfEdges);
            }
        }
        return answer;
    }
};