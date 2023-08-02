class Solution {
private:
    
    void backtrack(int startIndex, vector<int> &nums, vector<vector<int>> &ans)
    {
        if(startIndex == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        
        for(int i=startIndex; i<nums.size(); i++)
        {
            swap(nums[startIndex], nums[i]);
            backtrack(startIndex+1, nums, ans);
            swap(nums[startIndex], nums[i]);
        }
        
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        backtrack(0, nums, ans);
        return ans;
        
    }
};