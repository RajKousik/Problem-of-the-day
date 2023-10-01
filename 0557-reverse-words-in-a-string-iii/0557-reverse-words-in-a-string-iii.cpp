class Solution {
public:
    string reverseWords(string s) {
        
        int startingIndex = -1;
        int endingIndex;
        int n = s.size();
        
        for(int i=0; i<n; i++)
        {
            //if it is a space or last character    
            if(s[i] == ' ' or i==n-1)
            {
                //increase the startindex
                startingIndex++;
                
                //if it is a space , then endingindex will be i-1
                //if it is lsat character, endindex will be i
                s[i]==' ' ? endingIndex = i-1 : endingIndex = i;
                
                //reverse those indexes(words)
                while(startingIndex <= endingIndex)
                {
                    char temp = s[startingIndex];
                    s[startingIndex] = s[endingIndex];
                    s[endingIndex] = temp;
                    startingIndex++;
                    endingIndex--;
                }
                
                //change startindex to i, for next iteration
                startingIndex = i;
                
            }
            
        }
        
        //return the ans
        return s;
        
    }
};