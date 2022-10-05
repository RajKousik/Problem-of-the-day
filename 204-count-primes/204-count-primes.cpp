class Solution {
public:
    
    void sieve(vector<int> &primes, int n)
    {
        primes[1] = 1;
        primes[2] = 1;
        
        for(int i=2; i*i<=n; i++)
        {
            if(primes[i])
            {
                for(int j = i*i; j<=n; j+=i)
                {
                    primes[j] = false;
                }
            }
        }
    }
    
    int countPrimes(int n) {
        
        if(n==0 or n==1) return 0;
        
        vector<int> primes(n+1, 1);
        
        sieve(primes, n);
        
        int ans = 0;
        for(int i=2; i<n; i++)
        {
            if(primes[i])
            {
                ans++;
            }
        }
        
        return ans;
        
    }
};