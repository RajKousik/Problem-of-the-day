class Solution {
public:
    string multiply(string num1, string num2)
    {
        if(num1 == "0" or num2 == "0")
        {
            return "0";
        }
        
        int n1 = num1.size();
        int n2 = num2.size();
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        int i=0, j=0;
        
        int n = n1 + n2;
        
        string ans(n, '0');
        
        for(int j=0; j<n2; j++)
        {
            int d2 = num2[j] - '0';
            
            for(int i=0; i<n1; i++)
            {
                int d1 = num1[i] - '0';
                
                int position = i + j;
                
                int carry = ans[position] - '0';
                
                int sum = (d1 * d2) + carry;
                
                ans[position] = (sum % 10) + '0';
                
                ans[position+1] += (sum/10);
                
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