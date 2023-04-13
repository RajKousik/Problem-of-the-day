class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
    {
        
        int j = 0;
        
        stack<int> st;
        
        for(auto x : pushed)
        {
            st.push(x);
            while(!st.empty() and j < popped.size() and st.top() == popped[j])
            {
                st.pop();
                j++;
            }
            
        }
        
        return j == popped.size();
        
    }
};