class Solution {
public:
    
    int quickSelect(vector<int> &nums, int k)
    {
        int pivot = nums[rand() % nums.size()];
        
        vector<int> low, mid, high;
        
        for(int num : nums)
        {
            if(num > pivot)
            {
                low.push_back(num);
            }
            else if(num < pivot)
            {
                high.push_back(num);
            }
            else
            {
                mid.push_back(num);
            }
        }
        
        if(k <= low.size())
        {
            return quickSelect(low, k);
        }
        else if(low.size() + mid.size() < k)
        {
            return quickSelect(high, k - low.size() - mid.size());
        }

        return pivot;
        
    }
    
    
    int findKthLargest(vector<int>& nums, int k) {
        // priority_queue<int, vector<int>, greater<int>> pq;
        
//         for(auto it : nums)
//         {
//             pq.push(it);
//             if(pq.size() > k)
//             {
//                 pq.pop();
//             }
//         }
        
//         return pq.top();
//         priority_queue<int> pq;
        
//         for(auto it : nums)
//         {
//             pq.push(it);
//         }
        
//         while(--k) //for(int i=0; i<k-1; i++)
//         {
//             pq.pop();
//         }
        
//         return pq.top();
        
        // return quickSelect(nums, k);  // TC : BC: O(N) WC : O(N^2)
        return countAlgorithm(nums, k);  //TC : O( N + (max - min + 1)) //O(N+M) , M = (max - min + 1)
        
    }
    
    int countAlgorithm(vector<int> &nums, int k)
    {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int num : nums)
        {
            mini = min(mini, num);
            maxi = max(maxi, num);
        }
        vector<int> count(maxi - mini + 1);
        for(int num : nums)
        {
            count[num - mini]++;
        }
        int remain = k;
        for(int val = count.size()-1; val >= 0; val--)
        {
            remain -= count[val];
            if(remain <= 0)
            {
                return val + mini;
            }
        }
        return -1;
    }
    
};