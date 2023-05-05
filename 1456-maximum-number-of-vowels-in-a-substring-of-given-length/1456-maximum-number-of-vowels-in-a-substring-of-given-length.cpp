class Solution 
{
private:
    
    bool isVowel(char c)
    {
        return (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u');
    }
    
public:
    int maxVowels(string s, int k) 
    {
        
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
        int left = 0;
        int right = k;
        
        while(right < n)
        {
            if(isVowel(s[left]))
            {
                temp--;
            }
            
            if(isVowel(s[right]))
            {
                temp++;
            }
            
            left++;
            right++;
            ans = max(ans, temp);
        }
        
        return ans;
    }
};