//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	long long int NoOfChicks(int n){
	    // Code here
	    
	    long long sum = 1;
	    queue<long long> q;
	    
	    q.push(1);
	    
	    for(int i=1; i<n; i++)
	    {
	        if(q.size() == 6)
	        {
	            sum -= q.front();
	            q.pop();
	        }
	        
	        long long newBorn = sum * 2;
	        q.push(newBorn);
	        
	        sum += newBorn;
	        
	    }
	    
	    return sum;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution obj;
		long long int ans = obj.NoOfChicks(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends