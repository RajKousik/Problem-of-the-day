class Solution {
    
    void helper(int ind, vector<int> ds, vector<vector<int>> &ans, int n, int k)
    {
        if(ds.size() == k)
        {
            ans.push_back(ds);
            return;
        }        
        
        for(int i=ind; i<=n; i++)
        {
            if(i > ind)
            {
                ds.push_back(i);
                helper(i, ds, ans, n, k);
                ds.pop_back();
            }
        }
        
    }
    
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> ds;
        helper(0, ds, ans, n, k);
        return ans;
    }
};