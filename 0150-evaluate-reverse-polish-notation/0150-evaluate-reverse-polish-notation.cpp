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
        int fact = 1; 
        while(i>=0)
        {
            sum = (str[i]-'0')*fact + sum;
            i--;
            fact = fact * 10;
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
                        cout<<a<<" "<<b<<" "<<ans;
                    }
                    st.push(ans);
                }
            }
            else
            {
                st.push((long long)convertStrToNum(it));
            }
        }
        
        return (int)st.top();
        
    }
};