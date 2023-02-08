class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        
        int curEnd = 0;
        int curFar = 0;
        
        for(int i=0; i<n-1; i++)
        {
            curFar = max(curFar, i + nums[i]);
            
            if(i == curEnd)
            {
                ans++;
                curEnd = curFar;
            }
            
        }
        return ans;
    }
};