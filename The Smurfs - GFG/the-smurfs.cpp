//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int findMin(int n, char a[]){
        // code here
        //blue color - bc
        int bc=0, gc=0, rc=0;
        
        for(int i=0; i<n; i++){
            if(a[i] == 'R')
            {
                rc++;
            }
            else if(a[i] == 'G')
            {
                gc++;
            }
            else
            {
                bc++;
            }
        }
        
        //if all the balls are even
        if(rc%2 == 0 and bc%2 == 0 and gc % 2 == 0)
        {
            return 2;
        }
        //if all the balls are odd
        else if(rc%2 == 1 and bc%2 == 1 and gc % 2 == 1)
        {
            return 2;
        }
        //for all other cases
        return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        cout<<ob.findMin(n, a)<<"\n";
    }
    return 0;
}
// } Driver Code Ends