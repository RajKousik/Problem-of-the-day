//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
    
    int nextHappyNumber(int N)
    {
        if(N ==1 or N == 7)
        {
            return true;
        }
        if(N == 2 || N == 3 || N == 4 || N == 5 || N == 6 || N == 8 || N == 9)
        {
            return false;
        }
        
        int sq_sum = 0;
        while(N)
        {
            int digit = N % 10;
            sq_sum += (digit * digit);
            N /= 10;
        }
        
        return nextHappyNumber(sq_sum);
        
    }
    
public:
    int nextHappy(int N){
        // code here
        
        while(1)
        {
            N++;
            if(nextHappyNumber(N))
            {
                return N;
            }
        }
        
        return 0;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends