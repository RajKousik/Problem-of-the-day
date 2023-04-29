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

// class DSU {
// public:
//     vector<int> group;
//     vector<int> rank;

//     DSU(int size) {
//         group = vector<int>(size);
//         rank = vector<int>(size);
//         for (int i = 0; i < size; ++i) {
//             group[i] = i;
//         }
//     }

//     int find(int node) {
//         if (group[node] != node) {
//             group[node] = find(group[node]);
//         }
//         return group[node];
//     }

//     void unionBySize(int node1, int node2) {
//         int group1 = find(node1);
//         int group2 = find(node2);

//         // node1 and node2 already belong to same group.
//         if (group1 == group2) {
//             return;
//         }

//         if (rank[group1] > rank[group2]) {
//             group[group2] = group1;
//         } else if (rank[group1] < rank[group2]) {
//             group[group1] = group2;
//         } else {
//             group[group1] = group2;
//             rank[group2] += 1;
//         }
//     }

//     bool isConnected(int node1, int node2) {
//         int group1 = find(node1);
//         int group2 = find(node2);
//         return group1 == group2;
//     }
// };


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


// class Solution {
// public:
//     // Sort in increasing order based on the 3rd element of the array.
//     bool static compare(vector<int>& a, vector<int>& b) {
//         return a[2] < b[2];
//     }

//     vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
//         DSU uf(n);
//         int queriesCount = queries.size();
//         vector<bool> answer(queriesCount);

//         // Store original indices with all queries.
//         vector<vector<int>> queriesWithIndex(queriesCount);
//         for (int i = 0; i < queriesCount; ++i) {
//             queriesWithIndex[i] = queries[i];
//             queriesWithIndex[i].push_back(i);
//         }

//         int edgesIndex = 0;

//         // Sort all edges in increasing order of their edge weights.
//         sort(edgeList.begin(), edgeList.end(), compare);
//         // Sort all queries in increasing order of the limit of edge allowed.
//         sort(queriesWithIndex.begin(), queriesWithIndex.end(), compare);

//         // Iterate on each query one by one.
//         for (auto& query : queriesWithIndex) {
//             int p = query[0];
//             int q = query[1];
//             int limit = query[2];
//             int queryOriginalIndex = query[3];

//             // We can attach all edges which satisfy the limit given by the query.
//             while (edgesIndex < edgeList.size() && edgeList[edgesIndex][2] < limit) {
//                 int node1 = edgeList[edgesIndex][0];
//                 int node2 = edgeList[edgesIndex][1];
//                 uf.unionBySize(node1, node2);
//                 edgesIndex += 1;
//             }

//             // If both nodes belong to the same component, it means we can reach them. 
//             answer[queryOriginalIndex] = uf.isConnected(p, q);
//         }

//         return answer;
//     }
// };