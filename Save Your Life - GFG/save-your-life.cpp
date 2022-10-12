//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
        string maxSum(string w,char x[], int b[],int n){
          // code here    
          
            unordered_map<char, int> mp;
          
            for(int i=0; i<n; i++)
            {
                mp[x[i]] = b[i];
            }
          
            int maxTillNow = 0;
            int globalMax = INT_MIN;
            
            string ans = "";
            string temp = "";
          
            for(int i=0; i<w.size(); i++)
            {
              
                if(mp.find(w[i]) != mp.end())
                {
                    maxTillNow = max(maxTillNow + mp[w[i]], mp[w[i]]);
                    temp += w[i];
                    
                    if(maxTillNow > globalMax)
                    {
                        ans = temp;
                        globalMax = maxTillNow;
                    }
                    
                    if(maxTillNow < 0)
                    {
                        maxTillNow = 0;
                        temp = "";
                    }
                }
                else
                {
                    maxTillNow = max(maxTillNow + (int)w[i], (int)w[i]);
                    temp += w[i];
                    
                    if(maxTillNow > globalMax)
                    {
                        ans = temp;
                        globalMax = maxTillNow;
                    }
                    
                    if(maxTillNow < 0)
                    {
                        maxTillNow = 0;
                        temp = "";
                    }  
                  
                }
            }
          
          
          
          return ans;
          
      }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends