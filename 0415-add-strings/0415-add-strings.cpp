class Solution {
public:
    string addStrings(string num1, string num2) {
        
        int m = num1.size();
        int n = num2.size();
        
        int i = m-1;
        int j = n-1;
        
        int carry = 0;
        int sum = 0;
        
        string ans= "";
        
        while(i>=0 or j >=0 or carry)
        {
            int x = 0;
            if(i >= 0)
            {
                x = num1[i] - '0';
            }
            
            int y = 0;
            if(j >= 0)
            {
                y = num2[j] - '0';
            }
            
            sum = (x + y + carry) % 10;
            carry = (x + y + carry) / 10;
            
            ans.push_back((char)(sum + '0'));
            i--;
            j--;
            
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
        
    }
};