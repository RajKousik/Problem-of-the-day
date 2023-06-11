class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for(char ch : s)
        {
            if(ch != ']')
                st.push(ch);
            else
            {
                string currentString = "";
                while(!st.empty() and st.top() != '[')
                {
                    currentString = st.top() + currentString;
                    st.pop();
                }
                st.pop();   //removing ']'
                string numStr = "";
                while(!st.empty() and st.top() >= '0' and st.top() <= '9')
                {
                    numStr = st.top() + numStr;
                    st.pop();
                }
                int number = stoi(numStr);
                while(number--)
                {
                    for(auto ch : currentString)
                        st.push(ch);
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