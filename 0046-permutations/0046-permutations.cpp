class Solution {
    
    void backtrack(int index, vector<int> &nums, vector<vector<int>> &res)
    {
        if(index == nums.size())
        {
            res.push_back(nums);
            return;
        }
        
        for(int i=index; i<nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            backtrack(index+1, nums, res);
            swap(nums[index], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> res;
        backtrack(0, nums, res);
        return res;
        
    }
};