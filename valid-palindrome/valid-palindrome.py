class Solution:
    def isPalindrome(self, s: str) -> bool:
        
        str = ''
        for ch in s:
            if(ch.isalnum()):
               str += ch.lower() 
        
        if(str == str[::-1]):
            return 1
        else:
            return 0  #[start, end, step]
