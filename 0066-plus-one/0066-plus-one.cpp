class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        
        int n = digits.size();
        
        if(digits[n-1] != 9)
        {
            digits[n-1]++;
            return digits;
        }
        
        int j = n-1;
        
        while(j >=0 and digits[j] == 9)
        {
            digits[j] = 0;
            j--;
        }
        
        if(j>=0)
        {
            digits[j]++;
        }
        else
        {
            digits.insert(digits.begin(), 1);
        }
        
        return digits;
    }
};