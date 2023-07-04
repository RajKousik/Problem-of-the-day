class Solution {
private:
    
    vector<int> findNextSmaller(vector<int> &heights, int n)
    {
        vector<int> nextSmaller(n, 0);
        stack<int> st;
        
        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() and heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                nextSmaller[i] = st.top() - 1;
            }
            else
            {
                nextSmaller[i] = n-1;
            }
            st.push(i);
        }
        return nextSmaller;
    }
    
    vector<int> findPreviousSmaller(vector<int> &heights, int n)
    {
        vector<int> prevSmaller(n, 0);
        stack<int> st;
        
        for(int i=0; i<n; i++)
        {
            while(!st.empty() and heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                prevSmaller[i] = st.top() + 1;
            }
            else
            {
                prevSmaller[i] = 0;
            }
            st.push(i);
        }
        return prevSmaller;   
    }
    
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        
        // int previousSmaller(n, 0), nextSmaller(n, 0);
        
        vector<int> previousSmaller = findPreviousSmaller(heights, n);
        vector<int> nextSmaller = findNextSmaller(heights, n);
        
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            ans = max(ans, (heights[i] * (nextSmaller[i] - previousSmaller[i] + 1)));
            // cout<<previousSmaller[i]<<" "<<nextSmaller[i]<<endl;
        }
        
        return ans;
    }
};