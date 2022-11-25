class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        long ans = 0;
        
        int mod = 1e9+7;
        
        stack<int> st;
        
        for(int i=0; i<=arr.size(); i++)
        {
            while(!st.empty() and (i == arr.size() or arr[st.top()] >= arr[i]))
            {
                
                int mid = st.top();
                st.pop();
                
                int leftBoundary = st.empty() ? -1 : st.top();
                
                int rightBoundary = i;
                
                long count = (mid - leftBoundary) * (rightBoundary - mid) % mod;
                
                ans += (count * arr[mid]) % mod;
                
                ans = ans % mod;
                
            }
            st.push(i);
        }
        
        return (int)ans;
        
    }
};