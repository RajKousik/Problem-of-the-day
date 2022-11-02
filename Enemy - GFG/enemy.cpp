//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        int largestArea(int n,int m,int k,vector<vector<int>> &enemy)
        {
            //  code here
             vector<int> a,b;
            a.push_back(0);
            b.push_back(0);
            int mx1=0,mx2=0;
            for(auto &i:enemy){
                a.push_back(i[0]);
                b.push_back(i[1]);
            }
            a.push_back(n+1);
            b.push_back(m+1);
            sort(a.begin(),a.end());
            sort(b.begin(),b.end());
            for(int i=1;i<a.size();i++){
                mx1=max(mx1,a[i]-a[i-1]-1);
                mx2=max(mx2,b[i]-b[i-1]-1);
            }
            return mx1*mx2;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int k;
        cin>>k;
        vector<vector<int>> e(k,vector<int>(2));
        for(int i=0;i<k;i++)
            cin>>e[i][0]>>e[i][1];
        Solution a;
        cout<<a.largestArea(n,m,k,e)<<endl;
    }
    return 0;
}
// } Driver Code Ends