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
                dfs(i, isConnected, isVisited, n);
            }
        }
        
        return provinces;
    }
};