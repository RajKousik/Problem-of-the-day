//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    
    int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if(i == 0 or j == 0)
        {
            return 0;
        }
        
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        
        if(s1[i-1] == s2[j-1])
        {
            return dp[i][j] = 1 + solve(i-1, j-1, s1, s2, dp);
        }
        
        return dp[i][j] = max(solve(i, j-1, s1, s2, dp), solve(i-1, j, s1, s2, dp));
        
        
    }
    
    
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2)
    {
        // your code here
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(n, m, s1, s2, dp); 
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends