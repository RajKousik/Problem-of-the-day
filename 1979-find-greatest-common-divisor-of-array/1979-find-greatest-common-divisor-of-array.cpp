class Solution {
    
    int gcd(int a, int b)
    {
        if(!b) return a;
        return gcd(b, a%b);
    }
    
public:
    int findGCD(vector<int>& nums) {
        
        int maxi = INT_MIN, mini = INT_MAX;
        for(int num : nums)
        {
            maxi = max(maxi, num);
            mini = min(mini, num);
        }
        
        return gcd(mini, maxi);
        
    }
};