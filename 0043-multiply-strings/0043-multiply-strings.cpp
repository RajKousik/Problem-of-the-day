class Solution {
public:
    string multiply(string a, string b) 
    {
        
        //see solution tab for better understanding
        
        if(a == "0" or b == "0")
        {
            return "0";
        }

        int n1 = a.size();
        int n2 = b.size();

        int n = n1 + n2;

        string ans(n, '0');

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        for(int i=0; i<n2; i++)
        {
            int digit1 = b[i] - '0';

            for(int j=0; j<n1; j++)
            {
                int digit2 = a[j] - '0';

                int position = i + j;

                int carry = ans[position] - '0';

                int mul = (digit2 * digit1) + carry;

                ans[position] = mul%10 + '0';

                ans[position + 1] += mul/10;

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