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

        
        vector<vector<int>> ans;
        
        
        for(int i=2; i<=n/2; i++)
        {
            int complement = n - i;
            if(isPrime[i] and isPrime[complement])
            {
                ans.push_back({i, complement});
            }
        }
        
        
//         int i=2, j=n;        
//         while(i <= j)
//         {
//             int sum = i + j;
//             if(isPrime[i] and isPrime[j] and sum == n)
//             {
//                 ans.push_back({i, j});
//                 i++, j--;
//             }
//             else if(sum < n)
//             {
//                 i++;
//             }
//             else if(sum > n)
//             {
//                 j--;
//             }
//             else
//             {
//                 i++, j--;
//             }
//         }
        
        return ans;
    }
};