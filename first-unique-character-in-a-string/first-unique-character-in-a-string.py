class Solution:
    def firstUniqChar(self, s: str) -> int:
        
        isRepeat = 0
        for i in range(0,len(s)):
            isRepeat = 0
            for j in range(0, len(s)):
                if i!=j and s[i] == s[j]:
                    isRepeat = 1
                    break
            if(isRepeat == 0):
                return i
            
        return -1