//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    string isSumOfTwo(int N){
        // code here
        
        vector<int> isPrime(N+1, 1);
        
        isPrime[0] = 0;
        isPrime[1] = 0;
        
        for(int i=2; i*i<=N; i++)
        {
            if(isPrime[i] == 1)
            {
                for(int j=i*i; j<=N; j+=i)
                {
                    isPrime[j] = 0;
                }
            }
        }
        
        int i=0, j=N;
        
        
        while(i <= j)
        {
            if((isPrime[i] and isPrime[j]) and (i+j == N))
            {
                return "Yes";
            }
            else if(i + j < N)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return "No";
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isSumOfTwo(N) << endl;
    }
    return 0;
}

// } Driver Code Ends