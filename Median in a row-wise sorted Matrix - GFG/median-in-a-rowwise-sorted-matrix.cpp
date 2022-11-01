//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &mat, int r, int c){
        // code here          
         int low=INT_MAX;
        int high=INT_MIN;
        int ans;
        
        for(int i=0; i<r; i++)
        {
            low = min(low, mat[i][0]);
            high = max(high, mat[i][c-1]);
        }
        
        int noOfElements = (r * c + 1)/2;
        // the median should have atleast n/2 elements on its left 
        
        
        while(low < high)
        {
            
            int mid = low + (high - low)/2;
            
            int elements_in_this_row = 0;
            
            for(int i=0; i<r; i++)
            {
                 elements_in_this_row += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
            }
            
            if(elements_in_this_row < noOfElements)
            {
                low = mid + 1;
            }
            else
            {   
                // ans = mid;
                high = mid;
            }
            
        }
        
        return low;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}
// } Driver Code Ends