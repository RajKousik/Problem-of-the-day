//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int beautySum(string s) {
        // Your code goes here
        
        int ans = 0;
        
        for(int i=0; i<s.size(); i++)
        {
            vector<int> freq(26, 0);
            for(int j=i; j<s.size(); j++)
            {
                freq[s[j]-'a']++;
                
                ans += solve(freq);
                
            }
        }
        
        return ans;
        
    }
    
    int solve(vector<int> freq)
    {
        int mn = INT_MAX;
        int mx = INT_MIN;
        
        for(int it : freq)
        {
            if(it == 0) continue;
            mx = max(mx, it);
            mn = min(mn, it);
        }
        
        return mx - mn;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends