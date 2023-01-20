class Solution {
public:
    
    
    void func(int index, vector<int> &nums, vector<int> &temp, set<vector<int>> &ans, int n)
    {
        if(index == n)
        {
            if(temp.size() >= 2)
            {
                ans.insert(temp);
            }
            return;
        }
        

        if(temp.empty() or temp.back() <= nums[index])
        {
            temp.push_back(nums[index]); 
            func(index+1, nums, temp, ans, n);
            temp.pop_back();
        }
        
        func(index+1, nums, temp, ans, n);
        
    }
    
    
    
    
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        set<vector<int>> ans;
        vector<int> temp;
        
        int n = nums.size();
        
        func(0, nums, temp, ans, n);
        
        return vector(ans.begin(), ans.end());
        
    }
};