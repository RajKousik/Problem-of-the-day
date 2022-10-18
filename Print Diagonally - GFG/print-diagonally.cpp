//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> downwardDigonal(int N, vector<vector<int>> A)
	{
		// Your code goes here
		
		//trick -> go for uppper side first, and go lower triangle
		
		vector<int> ans;
		
		int n = A.size();
		
		//upper triangle
		//observe which one is constant here
		for(int i=0; i<n; i++)
		{
		    int start = 0;     //starting value's row is always constant, that is 0
		    int end = i;        //incrementing the start and decrementing the end will give the upper triangle
		    
		    while(start < n and end >= 0)   //boundary cases
		    {
		        ans.push_back(A[start][end]);
		        start++;
		        end--;
		    }
		}
		
		//lower triangle
		for(int i=1; i<n; i++)
		{
		    int start = i;      //starting row is always i
		    int end = n-1;      //starting column is always n-1
		    
		    while(start < n and end >= 0)   //boundary cases
		    {
		        ans.push_back(A[start][end]);
		        start++;
		        end--;
		    }
		    
		}
		
		return ans;
		
	}

};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends