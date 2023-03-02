class Solution {
public:
    int compress(vector<char>& chars) 
    {
        int i=0;
        
        int ans = 0;
        
        while(i < chars.size())
        {
            
            int groupLength = 1;
            
            while(i + groupLength < chars.size() and chars[i + groupLength] == chars[i])
            {
                groupLength++;
            }
            
            chars[ans++] = chars[i];
            
            if(groupLength > 1)
            {
                for(auto c : to_string(groupLength))
                {
                    chars[ans++] = c;
                }
            }
            
            i += groupLength;
            
        }
        return ans;
        
    }
};