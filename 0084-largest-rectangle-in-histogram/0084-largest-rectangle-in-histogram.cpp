class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        vector<int> previousSmaller(n), nextSmaller(n);
        stack<int> st;
        for(int i=0; i<n; i++) {
            while(!st.empty() and heights[st.top()] >= heights[i])
                st.pop();
            if(!st.empty())
                previousSmaller[i] = st.top() + 1;
            else
                previousSmaller[i] = 0;
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1; i>=0; i--){
            while(!st.empty() and heights[st.top()] >= heights[i])
                st.pop();
            if(!st.empty())
                nextSmaller[i] = st.top() - 1;
            else
                nextSmaller[i] = n-1;
            st.push(i);
        }
        int maxArea = 0;
        for(int i=0; i<n; i++)
        {
            int currentArea = heights[i] * (nextSmaller[i] - previousSmaller[i] + 1);
            maxArea = max(maxArea, currentArea);
        }
        return maxArea;
        
    }
};