class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) 
    {
        vector<int> ans;
        
        int x, y, carry = 0;
        
        int j = num.size() - 1;
        
        while(j>=0 or k > 0 or carry)
        {
            x = 0;
            if(j>=0)
            {
                x = num[j];
                j--;
            }
            y=0;
            if(k>0)
            {
                y = k%10;
                k/=10;
            }
            
            int sum = (x + y + carry) % 10;
            ans.push_back(sum);
            carry = (x + y + carry)/10;
            
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};