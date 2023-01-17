class Solution {
public:
    int minFlipsMonoIncr(string s) {
        
        int z = 0;
        
        for(auto it : s)
        {
            if(it == '0')
            {
                z++;
            }
        }
        
        int ans = z;
        
        for(auto it : s)
        {
            if(it == '0')
            {
                ans = min(ans, --z);
            }
            else
            {
                z++;
            }
        }
        
        return ans;
        
    }
};