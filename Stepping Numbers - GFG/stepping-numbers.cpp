//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:

    int steppingNumbers(int n, int m)
    {
        // Code Here
        int d[] = {0,1,2,3,4,5,6,7,8,9};
        
        queue<int> q;
        
        for(int i=1; i<=9; i++)
        {
            q.push(i);
        }
        
        int ans = 0;
        
        if(n == 0)
        {
            // cout<<n<<" "<<ans<<endl;
            ans++;
        }
        
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            
            if(node >= n and node <= m)
            {
                ans++;
                // cout<<node<<" "<<ans<<endl;
            }
            
            int child;
            int lastDigit = node%10;
            
            if(lastDigit != 0)
            {
                
                child = (node*10) + d[lastDigit - 1];
                if(child <= m)
                {
                    q.push(child);
                }
            }
            if(lastDigit != 9)
            {
                
                child = node*10 + d[lastDigit + 1];
                if(child <= m)
                {
                    q.push(child);
                }
            }
            
        }
        
        return ans;
        
    }
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        cout << obj.steppingNumbers(n,m) << endl;
    }
	return 0;
}


// } Driver Code Ends