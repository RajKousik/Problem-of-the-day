class Solution {
public:
    
    bool isVowel(char c)
    {
        return (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c =='u');
    }
    
    int maxVowels(string s, int k) 
    {
        // unordered_map<
        
        int ans = 0;
        int n = s.size();
        
        for(int i=0; i<k; i++)
        {
            if(isVowel(s[i]))
            {
                ans++;
            }
        }
        
        int temp = ans;
        
        int right = k;
        int left = 0;
        
        while(right < n)
        {
            if(isVowel(s[right]))
            {
                temp++;
            }
            
            if(isVowel(s[left]))
            {
                temp--;
            }
            
            left++;
            right++;
            
            ans = max(ans, temp);
        }
        
        return ans;
        
    }
};