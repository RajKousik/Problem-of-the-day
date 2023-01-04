class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        
        for(int i=0; i<s.size(); i++)
        {
            char ch = s[i];
            
            if(ch == '(' or ch == '{' or ch == '[')
            {
                st.push(ch);
            }
            else
            {
                if(st.empty())
                {
                    return false;
                }
                
                if(ch == ')')
                {
                    if(st.top() == '(')
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else if(ch == ']')
                {
                    if(st.top() == '[')
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else if(ch == '}')
                {
                    if(st.top() == '{')
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            
        }
        return st.empty();
    }
};