class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        
        int ans = 0;
        
        if(n == 1) return true;
        
        for(int i=0; i<n and i <= ans; i++)
        {

            ans = max(ans, i + nums[i]);
            if(ans >= n-1)
            {
                return true;
            }

            
        }
        
    
        
        return false;
        
    }
};