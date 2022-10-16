class Solution {
public:
    
    void solve(int ind, int sum, vector<int>& candidates, int target, vector<int> temp, vector<vector<int>> &ans)
    {
        
        if(ind == candidates.size() and target == sum)
        {
            ans.push_back(temp);
            return;
        }
        
        if(ind >= candidates.size() or sum > target)
        {
            return;
        }
            
        temp.push_back(candidates[ind]);
        solve(ind + 1, sum + candidates[ind], candidates, target, temp, ans);
        
        temp.pop_back();
        
        while(ind + 1 < candidates.size() and candidates[ind] == candidates[ind+1])
        {
            ind++;
        }
        
        solve(ind + 1, sum, candidates, target, temp, ans);

    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> ans;
        vector<int> temp;
        
        solve(0, 0, candidates, target, temp, ans);
        
        return ans;
    }
};