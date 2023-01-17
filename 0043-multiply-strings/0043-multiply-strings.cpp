class Solution {
public:
    string multiply(string num1, string num2) {
        
        //see solution tab for better understanding
        
        if(num1 == "0" or num2 == "0")
        {
            return "0";
        }
        
        int n1 = num1.size();
        int n2 = num2.size();
        
        int n = n1 + n2;
        
        string ans(n, '0');
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        for(int i=0; i<n2; i++)
        {
            int digit1 = num2[i] - '0';
            for(int j=0; j<n1; j++)
            {
                int digit2 = num1[j] - '0';
                
                int position = i + j;
                
                int carry = ans[position] - '0';
                
                int mul = (digit1 * digit2) + carry;
                
                ans[position] = (mul%10) + '0';
                
                ans[position + 1] += (mul/10);
                
            }
        }
        
        while(ans.back() == '0')
        {
            ans.pop_back();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
        
    }
};