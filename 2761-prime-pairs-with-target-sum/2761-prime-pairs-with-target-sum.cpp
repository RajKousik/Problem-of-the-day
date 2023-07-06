class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        
        vector<bool> isPrime(n+1, true);
        isPrime[0] = false;
        isPrime[1] = false;
        
        for(int i=2; i*i <= n; i++)
        {
            if(isPrime[i])
            {
                for(int j=i*i; j<=n; j+=i)
                {
                    isPrime[j] = false;
                }
            }
        }
        
        // for(int i=0; i<=n; i++)
        // {
        //     cout<<i<<isPrime[i]<<endl;
        // }
        
        int i=2, j=n;
        vector<vector<int>> ans;
        
        while(i <= j)
        {
            int sum = i + j;
            if(isPrime[i] and isPrime[j] and sum == n)
            {
                ans.push_back({i, j});
                i++, j--;
            }
            else if(sum < n)
            {
                i++;
            }
            else if(sum > n)
            {
                j--;
            }
            else
            {
                i++, j--;
            }
        }
        
        return ans;
    }
};