class Solution {
public:
    
    int convertStrToNum(string str)
    {
        bool isMinus = false;
        if(str[0] == '-')
        {
            str = str.substr(1);
            isMinus = true;
        }
        
        int i=str.size()-1;
        int sum = 0;
        // int fact = 1;
        reverse(str.begin(), str.end());
        while(i>=0)
        {
           sum = (sum * 10) + (str[i]-'0');
            i--;
        }
        return isMinus ? -1*sum : sum;
    }
    
    bool isOperator(string s)
    {
        if(s == "+" or s == "-" or s == "*" or s == "/")
        {
            return true;
        }
        return false;
    }
    
    int evalRPN(vector<string>& tokens) {
        
        stack<long long> st;
        
        for(auto it : tokens)
        {
            if(isOperator(it))
            {
                if(!st.empty())
                {
                    long long b = st.top();
                    st.pop();
                    long long a = st.top();
                    st.pop();
                    
                    long long ans;
                    
                    if(it == "+")
                    {
                        ans = a + b;
                    }
                    else if(it == "-")
                    {
                        ans = a - b;
                    }
                    else if(it == "*")
                    {
                        ans = a * b;
                    }
                    else if(it == "/")
                    {
                        ans = a / b;
                    }
                    st.push(ans);
                }
            }
            else
            {
                st.push((long long)(stoi(it)));
                // st.push((long long)convertStrToNum(it));
            }
        }
        
        return (int)st.top();
        
    }
};