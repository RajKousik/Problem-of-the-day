//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        // code here
        stack<char> st;
        
        int n = s.size();
        
        for(int i=0; i<n; i++)
        {
            
            if(s[i] != ']')
            {
                st.push(s[i]);
            }
            else
            {
                string temp = "";
                while(!st.empty() and st.top() != '[')
                {
                    temp = st.top() + temp;
                    st.pop();
                }
                st.pop();
                
                string n = "";
                
                while(!st.empty() and isdigit(st.top()) )
                {
                    n = st.top() + n;
                    st.pop();
                }
                
                int num = stoi(n);
                
                // cout<<num<<" ";
                
                string repeat = "";
                
                while(num--)
                {
                    repeat = repeat + temp;
                }
                
                for(int i=0; i<repeat.size(); i++)
                {
                    st.push(repeat[i]);
                }
                
            }
            
        }
        
        string ans = "";
        
        while(!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends