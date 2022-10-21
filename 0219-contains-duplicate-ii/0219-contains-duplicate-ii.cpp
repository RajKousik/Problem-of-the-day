class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& arr, int k) 
    {
        unordered_map<int, int> umap;
        
        for(int i=0; i<arr.size(); i++)
        {
            if(umap.find(arr[i]) != umap.end())
            {
                if(abs(umap[arr[i]] - i) <= k)
                {
                    cout<<"hi"<<i;
                    return true;
                }
            }
            umap[arr[i]] = i;
        }
        
        return false;
    }
};