class Solution {
private:
    
    bool isValid(vector<int>& piles, long long int mid, int h)
    {
        long long int k = 0;
        
        for(int i=0; i<piles.size(); i++)
        {
            if(piles[i]%mid == 0)
            {
                k += (piles[i]/mid);
            }
            else
            {
                k += (piles[i]/mid) + 1;
            }
        }
        return k <= h;
    }
    
public:
    int minEatingSpeed(vector<int>& piles, int h)
    {
        
        long long int low = 1;
        long long int high = INT_MIN;
        
        for(auto it : piles)
        {
            // low = min(low, it);
            high = max(high, (long long)it);
        }
        
        long long int ans;
        
        // cout<<low<<high<<" ";
        
        while(low <= high)
        {
            long long int mid = low + (high - low)/2;
            
            if(isValid(piles, mid, h))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
            
        }
        return ans;
        
    }
};