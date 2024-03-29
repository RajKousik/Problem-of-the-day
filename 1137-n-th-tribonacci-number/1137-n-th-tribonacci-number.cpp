class Solution {
    
    int f(int n, vector<int> &dp)
    {
        if(n==0) return 0;
        if(n==1 or n==2) return 1;
        
        if(dp[n] != -1)
        {
            return dp[n];
        }
        
        return dp[n] = f(n-1, dp) + f(n-2, dp) + f(n-3, dp);
    }
    
public:
    int tribonacci(int n) {
        
//         if(n == 0)
//         {
//             return 0;
//         }
        
//         if(n == 1 or n == 2) return 1;
        
        
//         int a = 0;
//         int b = 1;
//         int c = 1;
        
//         int sum = 0;
//         for(int i=3; i<=n; i++)
//         {
//             sum = a + b + c;
//             a = b;
//             b = c;
//             c = sum;  
//         }
        
//         return sum;
        vector<int> dp(n+1, -1);
        return f(n, dp);
        
    }
};