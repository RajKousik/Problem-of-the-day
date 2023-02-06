class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        vector<int> ans(2*n);
        int i=0;
        int j=n; 
        int k=0;
        while(k < 2 *n)
        {
            ans[k++] = (nums[i++]);
            ans[k++] = (nums[j++]);
        }
        return ans;
        
    }
};