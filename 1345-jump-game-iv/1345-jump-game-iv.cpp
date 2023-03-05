class Solution {
public:
    int minJumps(vector<int>& arr)
    {
        
        int n = arr.size();
        
        unordered_map< int, vector<int> > umap;
        
        for(int i=0; i<n; i++)
        {
            umap[arr[i]].push_back(i);
        }
        
        int steps = 0;
        queue<int> q;
        q.push(0);
        
        vector<bool> visited(n, false);
        visited[0] = true;
        
        while(!q.empty())
        {
            
            int size = q.size();
            
            while(size--)
            {
                
                int node = q.front();
                q.pop();
                
                if(node == n-1)
                {
                    return steps;
                }
                
                vector<int> &nextNodes = umap[arr[node]];
                nextNodes.push_back(node-1);
                nextNodes.push_back(node+1);
                
                for(auto it : nextNodes)
                {
                    if(it >= 0 and it < n and !visited[it])
                    {
                        q.push(it);
                        visited[it] = true;
                    }
                }
                nextNodes.clear();
            }
            
            steps++;
            
        }
        
        return -1;
    }
};