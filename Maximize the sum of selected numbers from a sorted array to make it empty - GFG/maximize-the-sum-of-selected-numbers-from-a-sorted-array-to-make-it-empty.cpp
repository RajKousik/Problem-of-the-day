//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
  

// } Driver Code Ends
class Solution{
    public:
    int maximizeSum(int a[], int n) 
    {
        // Complete the function
        //array is sorted in the driver code itself
        
        unordered_map<int, int> mp;
        
        for(int i=0; i<n; i++)
        {
            mp[a[i]]++;
        }
        
        int ans = 0;
        for(int i=n-1; i>=0; i--)
        {
            if(mp.find(a[i]) != mp.end())
            {
                ans += a[i];
                if(mp[a[i]] == 1)
                {
                    mp.erase(a[i]);
                }
                else
                {
                    mp[a[i]]--;
                }
                
                if(mp.find(a[i] - 1) != mp.end())
                {
                    if(mp[a[i] - 1] == 1)
                    {
                        mp.erase(a[i] - 1);
                    }
                    else
                    {
                        mp[a[i] - 1]--;
                    }
                }
            }
        }
        return ans;
        
    }

};


//{ Driver Code Starts.



int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr, arr+n);
        Solution ob;
        
        cout << ob.maximizeSum(arr, n) << endl;
        
        
    }

}


// } Driver Code Ends