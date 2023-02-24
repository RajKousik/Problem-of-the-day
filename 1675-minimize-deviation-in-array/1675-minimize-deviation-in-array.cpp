class Solution {
public:
    int minimumDeviation(vector<int>& nums)
    {
        
        int n = nums.size();
        priority_queue<int> pq;
        
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        for(int i=0; i<n; i++)
        {
            if(nums[i] % 2 == 1)
            {
                nums[i] *= 2;
            }
            
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[i]);
            pq.push(nums[i]);
        }
        
        int ans = maxi - mini;
        
        while(pq.top() % 2 == 0)
        {
            auto top = pq.top();
            pq.pop();
            
            ans = min(ans, top - mini);
            top/=2;
            
            mini = min(mini, top);
            pq.push(top);
        }
        
        ans = min(ans, pq.top() - mini);
        
        return ans;
        
        
    }
};