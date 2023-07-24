class Solution {
private:
    double calculatePower(double x, long long n)
    {
        if(n == 0) return 1.0;
        if(n < 0)
            return calculatePower(1/x, -1*n);
        if(n % 2 == 1)
            return x * calculatePower(x*x, n/2);
        else
            return calculatePower(x*x, n/2);
        return 0.0;
    }
public:
    double myPow(double x, int n) {
        //binary exponential
        // 2^100 == 4^50 == 16^25 == 16*(16^24) == 
        //     16^24 == 256 ^ 12 == (256*256)^6 == (x*x)^3 == x * (x*x)^1
        //******** Square the Digit and Half the Power *******//
        //handle negative cases
        // x^-n => 1/(x^-n) ===> if n = -8 ===> 1/n^-(-8) ===> 1/n^8
        //as we r using negative numbers, there may be an overflow for integer, so one should use long long
        return calculatePower(x, (long long)n);
    }
};