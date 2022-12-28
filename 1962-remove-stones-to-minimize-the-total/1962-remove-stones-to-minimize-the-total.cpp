class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        priority_queue<int> pq;
        
        for(auto it : piles)
        {
            pq.push(it);
        }
        
        while(!pq.empty() and k--)
        {
            auto it = pq.top();
            pq.pop();
            
            it = (it+1)/2;
            pq.push(it);
        }
        
        int ans = 0;
        while(!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }
        
        return ans;
        
    }
};