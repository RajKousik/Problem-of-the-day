// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        
        //holds the next larger elements for all the elements
        vector<long long> ans(n, -1);
        
        //stack 
        stack<long long> st;
        //initailly, last element will be pushed
        st.push(arr[n-1]);
        
        //as there is no larger element for last element, it always will be -1;
        ans[n-1] = -1;
        
        //iterate from right to left i.e => n-2 -> 0
        for(int i=n-2; i>=0; i--)
        {
            //if the top of the stack holds the smaller element than the current element
            // then pop it out, 
            // as we are interested in finding the next larger element 
            while(!st.empty() and st.top() <= arr[i])
            {
                st.pop();
            }
            
            //if we popped out all the elements,then the stack will be empty
            // which indicates that there is no larger element for current element
            // so simply push -1
            // if(st.empty())
            // {
            //     ans[i] = -1;
            // }
            // else                        // now stack top points out the element which is larger than the current element
            // {
            if(!st.empty())
                ans[i] = st.top();      // so push that element for current index
            // }
            
            st.push(arr[i]);            //push the current element in to the stack for future operations
        }
        
        
        //return the ans array which holds the next greater element for all the values <3 
        return ans;
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends