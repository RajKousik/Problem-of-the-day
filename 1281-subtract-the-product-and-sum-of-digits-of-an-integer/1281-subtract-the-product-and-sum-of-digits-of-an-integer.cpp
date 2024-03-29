class Solution {
public:
    int subtractProductAndSum(int n) {
        
        int prod = 1, sum = 0;
        
        while(n)
        {
            int digit = n % 10;
            prod = prod * digit;
            sum = sum + digit;
            n/=10;
        }
        
        return prod - sum;
        
    }
};