class Solution {
public:
    bool detectCapitalUse(string word) {
         
        bool match1 = true;
        
        for(auto it : word)
        {
            cout<<it;
            if(it < 'A' or it > 'Z')
            {
                
                match1 = false;
                break;
            }
        }
        
        if(match1)
        {
            cout<<"1";
            return true;
        }
        
        
        bool match2 = true;
        
        for(auto it : word)
        {
            if(it < 'a' or it > 'z')
            {
                match2 = false;
                break;
            }
        }
        
        if(match2)
        {
            cout<<"2";
            return true;
        }
        
        
        
        
        bool match3 = true;
        
        if(word[0] < 'A' and word[0] > 'Z') match3 = false;
        
        if(!match3) return false;
        
        for(int i=1; i<word.size(); i++)
        {
            if(word[i] < 'a' or word[i] > 'z')
            {
                match3 = false;
                break;
            }
        }
        
        if(match3)
        {
            cout<<"3";
            return true;
        }
        
        
        return false;
    }
};