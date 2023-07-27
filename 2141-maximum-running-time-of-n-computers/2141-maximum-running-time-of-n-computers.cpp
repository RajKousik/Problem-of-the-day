class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        
        long long low = 1;
        
        long long totalPower = 0;
        
        for(auto it : batteries)
        {
            totalPower += it;
        }
        
        long long high = totalPower/n;
        long long ans = -1;
        
        while(low <= high)
        {
            
            long long mid = (high + low)/2;
            
            long long temp = 0;
            
            for(auto it : batteries)
            {
                temp += (mid < it) ? mid : it;
            }
            
            if(temp >= (long long)(n * mid))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
            
        }
        
        return ans;
        
        
    }
};