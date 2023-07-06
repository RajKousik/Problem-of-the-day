class Solution {
public:
    int getLucky(string s, int k) {
        
        int num = 0;
        string str="";
        for(auto ch : s)
        {
            int digit = ch - 'a' + 1;
            num += (digit < 10) ? digit : ((digit / 10) + (digit % 10));
        }

        k--;        //already performed one operation
        int ans = num;
        while(k--)
        {
            ans = 0;
            while(num)
            {
                ans += (num % 10);
                num /= 10;
            }
            num = ans;
            
        }
        
        return ans;
        
    }
};