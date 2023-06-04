class Solution 
{

private:
    
    void dfs(int node, vector<vector<int>>& isConnected, vector<bool> &isVisited, int n)
    {
        
        isVisited[node] = true;
        
        for(int i=0; i < n; i++)
        {
            if(isConnected[node][i] and !isVisited[i])
            {
                dfs(i, isConnected, isVisited, n);
            }
        }
        
    }
    
    void bfs(int node, vector<vector<int>>& isConnected, vector<bool> &isVisited, int n)
    {
        
        queue<int> q;
        q.push(node);
        
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            
            for(int i=0; i<n; i++)
            {
                if(isConnected[it][i] and !isVisited[i])
                {
                    q.push(i);
                    isVisited[i] = true;
                }
            }
        }
        
    }
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n = isConnected.size();
        
        vector<bool> isVisited(n, false);
        
        int provinces = 0;
        for(int i=0; i<n; i++)
        {
            if(isVisited[i] == false)
            {
                provinces++;
                // dfs(i, isConnected, isVisited, n);
                bfs(i, isConnected, isVisited, n);
            }
        }
        
        return provinces;
    }
};