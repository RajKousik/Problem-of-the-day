class UnionFind
{
private:
    vector<int> parent, rank;
    
public:
    
    UnionFind(int size)
    {
        rank.resize(size, 0);
        parent.resize(size);
        
        for(int i=0; i<size; i++)
        {
            parent[i] = i;
        }
        
    }
    
    int findParent(int x)
    {
        if(parent[x] == x)
        {
            return x;
        }
        
        return parent[x] = findParent(parent[x]);
    }
    
    void unionByRank(int x, int y)
    {
        x = findParent(x);
        y = findParent(y);
        
        if(x == y)
        {
            return;
        }
        
        if(rank[x] < rank[y])
        {
            parent[x] = y;
        }
        else if(rank[y] < rank[x])
        {
            parent[y] = x;
        }
        else
        {
            parent[y] = x;
            rank[x]++;
        }
        
    }
    
};



class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        
        int n = vals.size();
        vector<vector<int>> adj(n);
        
        for(auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        
        map<int, vector<int>> sets;
        
        for(int i=0; i<n; i++)
        {
            sets[vals[i]].push_back(i);
        }
        
        UnionFind dsu(n);
        
        int goodPaths = 0; //answer
        
        for(auto it : sets) //int, vector<int>
        {
            for(auto node : it.second)
            {
                for(auto neighbor : adj[node])
                {
                    if(vals[neighbor] <= vals[node])
                    {
                        dsu.unionByRank(neighbor, node);
                    }
                }
            }
            
            unordered_map<int, int> group;
            
            for(auto node : it.second)
            {
                group[dsu.findParent(node)]++;
            }
            
            for(auto temp : group) //int, int (_, size)
            {
                int sizeOfThisSet = temp.second;
                goodPaths += (sizeOfThisSet * (sizeOfThisSet + 1))/2;
            }
        }
        
        return goodPaths;
    }
};