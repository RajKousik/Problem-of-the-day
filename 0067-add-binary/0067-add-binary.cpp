class Solution {
public:
    string addBinary(string a, string b)
    {
        int i = a.size()-1;
        int j = b.size()-1;
        
        int x, y, sum, carry = 0;
        
        string ans = "";
        
        while(i>=0 or j>=0 or carry)
        {
            x = 0;
            if(i >= 0)
            {
                x = a[i] - '0';
            }
            y=0;
            if(j>=0)
            {
                y = b[j] - '0';
            }
            
            sum = (x + y + carry) % 2;
            carry = (x + y + carry) / 2;
            
            ans.push_back((sum + '0'));
            
            i--;
            j--;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};