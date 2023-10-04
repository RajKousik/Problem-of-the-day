//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        // code here
        unordered_map<char, int> umap;
        
        umap['I'] = 1;
        umap['V'] = 5;
        umap['X'] = 10;
        umap['L'] = 50;
        umap['C'] = 100;
        umap['D'] = 500;
        umap['M'] = 1000;
        
        int ans = 0;
        int n = str.size();
        
        for(int i=0; i<n-1; i++)
        {
            if(umap[str[i]] < umap[str[i+1]])
            {
                ans -= umap[str[i]];
            }
            else
            {
                ans += umap[str[i]];
            }
        }
        ans += umap[str[n-1]];
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends