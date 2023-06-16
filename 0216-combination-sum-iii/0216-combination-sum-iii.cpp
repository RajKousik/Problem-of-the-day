class Solution {

private:
    
    void dfs(int start, int n, int k, vector<int> temp, vector<vector<int>> &ans)
    {
        if(temp.size() == k and n == 0)
        {
            ans.push_back(temp);
            return;
        }
        
        
        if(k == 0) return;
        
        for(int index = start; index <= 9; index++)
        {
            if(index <= n)
            {
                temp.push_back(index);
                dfs(index+1, n-index, k, temp, ans);
                temp.pop_back();
            }
        }
        
    }

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        
        dfs(1, n, k, temp, ans);
        
        return ans;
    }
};