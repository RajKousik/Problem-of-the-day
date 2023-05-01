class Solution {
public:
    double average(vector<int>& salary) 
    {
        
        int maxi = INT_MIN;
        int mini = INT_MAX;
        
        int n = salary.size();
        
        int sum = 0;
        
        for(auto it : salary)
        {
            maxi = max(maxi, it);
            mini = min(mini, it);
            sum += it;
        }
        
        sum = sum - maxi - mini;
        
        double ans = 0;
        ans = (double)(sum * 1.0) / (n-2);
        return ans;
    }
};