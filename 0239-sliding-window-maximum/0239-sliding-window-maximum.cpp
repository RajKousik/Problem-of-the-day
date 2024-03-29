class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> dq;
	
        int n = nums.size();
        for(int i=0; i<k; i++)
        {
            while(!dq.empty() and nums[i] >= nums[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        vector<int> ans;
        ans.push_back(nums[dq.front()]);

        for(int i=k; i<n; i++)
        {
            if(dq.front() == i-k)
            {
                dq.pop_front();
            }

            while(!dq.empty() and nums[i] >= nums[dq.back()])
            {
                dq.pop_back();
            }

            dq.push_back(i);
            ans.push_back(nums[dq.front()]);
        }
        return ans;
        
    }
};