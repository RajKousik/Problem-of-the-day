class DSU
{
private:
  vector<int> parent;
  vector<int> size;
  int components;
   
public:


  DSU(int n)
  {
    
     components = n;
    
    parent.resize(n+1);
    size.resize(n+1);
    for(int i=0; i<=n; i++)
    {
      parent[i] = i;
      size[i] = 1;
    }
  }
   
  int findParent(int node)
  {
    if(parent[node] == node)
    {
      return node;
    }
     
    return parent[node] = findParent(parent[node]);
  }
   
  int join(int u, int v)
  {
     
    int uParent = findParent(u);
    int vParent = findParent(v);
     
    if(uParent == vParent)
    {
      return 0;
    }
     
    if(size[uParent] < size[vParent])
    {
      parent[uParent] = vParent;
      size[vParent] += size[uParent];
    }
    else
    {
      parent[vParent] = uParent;
      size[uParent] += size[vParent];
    }
    
    components--;
    return 1;
      
  }
    
    bool isConnected()
    {
        return components == 1;
    }
   
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) 
    {
        DSU alice(n), bob(n);
        
        int edgesRequired = 0;
        int totalEdges = edges.size();
        
        for(auto it : edges)
        {
            if(it[0] == 3)
            {
                int u = it[1];
                int v = it[2];
                
                edgesRequired += ( (alice.join(u, v)) | (bob.join(u, v)) );
            }
        }
        
        for(auto it : edges)
        {
            int u = it[1];
            int v = it[2];
            
            if(it[0] == 1)
            {
                edgesRequired += (alice.join(u, v));
            }
            else if(it[0] == 2)
            {
                edgesRequired += (bob.join(u, v));
            }
        }
        
        if(alice.isConnected() and bob.isConnected())
        {
            return totalEdges - edgesRequired;
        }
        
        return -1;
        
    }
};