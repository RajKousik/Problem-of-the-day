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
        
        return quickSelect(nums, k);
            
        
    }
};