class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        
        int n = arr.size();
        stack<pair<int, int>> st;
        
        vector<int> ans(n, 0);
        
        for(int i=n-1; i>=0; i--)
        {

            while(!st.empty() and st.top().first <= arr[i])
            {
                // cout<<st.top()<<" "<<arr[i]<<endl;
                st.pop();
            }
            
            if(!st.empty())
            {
                ans[i] = abs(i - st.top().second);
            }
            
            st.push({arr[i], i});
        }
        return ans;
    }
};