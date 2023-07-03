//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        // code here
        vector<int> suffixMax(n, 0);
        
        suffixMax[n-1] = arr[n-1];
        
        for(int i=n-2; i>=0; i--)
        {
            suffixMax[i] = max(arr[i], suffixMax[i+1]);
        }
        
        int i=0, j=0, ans=-1;
        
        while(i < n and j < n)
        {
            if(arr[i] <= suffixMax[j])
            {
                j++;
            }
            else
            {
                i++;
            }
            ans = max(ans, j-i-1);
        }
        return ans;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends