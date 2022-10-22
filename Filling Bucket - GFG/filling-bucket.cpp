//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int mod = 1e8;

  
    int fillingBucket(int N) {
        // code here
        int secondLast = 1;
        int last = 1;
        
        for(int i=2; i<=N; i++)
        {
            int temp = (secondLast + last) % mod;
            secondLast = last;
            last = temp;
        }
        
        return last;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends