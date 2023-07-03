class Solution:
    def isPalindrome(self, s: str) -> bool:
        
        # s = ''.join(ch.lower() for ch in s if ch.isalnum())
        str = ''
        for ch in s:
            if(ch.isalnum()):
               str += ch.lower() 
        
    # Check if the string is equal to its reverse
        return str == str[::-1] #[start, end, step]
