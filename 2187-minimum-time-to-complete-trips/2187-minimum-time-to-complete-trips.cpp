class Solution {
private:
    
    bool isValid(long long value, vector<int>& time, int totalTrips)
    {
        long long tripsDone = 0;
        
        for(auto it : time)
        {
            tripsDone += (value / it);
        }
        
        return tripsDone >= totalTrips;
        
    }
    
public:
    long long minimumTime(vector<int>& time, int totalTrips) 
    {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        for(auto it : time)
        {
            // mini = min(mini, it);
            maxi = max(maxi, it);
        }
        
        // long long low = mini * totalTrips;
        long long low = 1;
        long long high = 1LL * *max_element(time.begin(), time.end()) * (totalTrips);
        
        long long ans = -1;
        
        while(low <= high)
        {
            
            long long mid = low + (high - low)/2;
            
            if(isValid(mid, time, totalTrips))
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