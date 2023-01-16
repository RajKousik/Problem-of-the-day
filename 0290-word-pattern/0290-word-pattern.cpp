class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        vector<string> words;
        
        string word;
        
        stringstream ss(s);
        
        while(ss >> word)
        {
            words.push_back(word);
        }
        
        if(pattern.size() != words.size())
            return false;
        
        set<string> st;
        map<char, string> mp;
        
        
        for(int i=0; i<pattern.size(); i++)
        {
            char currentChar = pattern[i];
            
            if(mp.find(currentChar) != mp.end())
            {
                if(mp[currentChar] != words[i])
                {
                    return false;
                }
            }
            else
            {
                if(st.find(words[i]) != st.end())
                {
                    return false;
                }
                st.insert(words[i]);
                mp[currentChar] =  words[i];
            }
        }
        return true;
    }
};