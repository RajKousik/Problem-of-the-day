class Solution {
public:
    int longestPalindrome(string s) {
        
        int res = 0;
        unordered_map<char, int> freq;
        
        for(auto c : s)
        {
            freq[c]++;
        }
        
        bool isOdd = false;
        
        for(auto it : freq)
        {
            if(it.second % 2 == 0)
            {
                res += it.second;
            }
            else
            {
                isOdd = true;
                res += it.second - 1;       // (aka) res + = (it.second % 2)
            }
        }
        
        return isOdd ? ++res : res;
        
    }
};