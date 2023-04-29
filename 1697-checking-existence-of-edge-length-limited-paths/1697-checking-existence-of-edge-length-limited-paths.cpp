class DSU
{
private:
  vector<int> parent;
  vector<int> size;
   
public:


  DSU(int n)
  {
    parent.resize(n+1);
    size.resize(n+1);
    for(int i=0; i<=n; i++)
    {
      parent[i] = i;
      size[i] = 0;
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
   
  void unionBySize(int u, int v)
  {
     
    int uParent = findParent(u);
    int vParent = findParent(v);
     
    if(uParent == vParent)
    {
      return;
    }
     
    if(size[uParent] < size[vParent])
    {
      parent[uParent] = vParent;
      size[vParent] += size[uParent];
      
    }
    else if(size[uParent] > size[vParent])
    {
      parent[vParent] = uParent;
      size[uParent] += size[vParent];
    }
    else
    {
        parent[uParent] = vParent;
        size[vParent] += 1;
    }
  }
    
  bool isConnected(int u, int v)
  {
      int uParent = findParent(u);
      int vParent = findParent(v);
      
      return uParent == vParent;
  }
   
};

class Solution {
    
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[2] < b[2];
    }
    
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) 
    {
        
        DSU dsu(n);
        
        int queriesSize = queries.size();
        
        vector<vector<int>> queriesWithIndex(queriesSize);
        
        int edges = edgeList.size();
        
        
        for(int i=0; i<queriesSize; i++)
        {
            queries[i].push_back(i);
            queriesWithIndex[i] = queries[i];
        }
        
        
        sort(queriesWithIndex.begin(), queriesWithIndex.end(), comp);
        
        sort(edgeList.begin(), edgeList.end(), comp);
        
        int indexCount = 0;
        
        vector<bool> isPossible(queriesSize);
        
        for(auto &query : queriesWithIndex)
        {
            int u = query[0];
            int v = query[1];
            
            int limit = query[2];
            int originalIndex = query[3];
            
            while(indexCount < edges and edgeList[indexCount][2] < limit)
            {
                
                int node1 = edgeList[indexCount][0];
                int node2 = edgeList[indexCount][1];
                
                //TOOD: connect step
                dsu.unionBySize(node1, node2);
                
                indexCount++;
            }
            
            isPossible[originalIndex] = dsu.isConnected(u, v);
            
        }

        
        
        return isPossible;
        
    }
};
