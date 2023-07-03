class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size())
        {
            return false;
        }
        
        if(s == goal)
        {
            vector<int> freq(26, 0);
            for(int i=0; i<s.size(); i++)
            {
                freq[s[i]-'a']++;
                if(freq[s[i]-'a'] == 2)
                {
                    return true;
                }
            }
        }
        
        int firstChange = -1, secondChange = -1;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] != goal[i])
            {
                if(firstChange == -1)
                {
                    firstChange = i;
                }
                else if(secondChange == -1)
                {
                    secondChange = i;
                }
                else
                {
                    return false;
                }
            }
        }
        
        if(secondChange == -1)
        {
            return false;
        }
        
        return goal[firstChange] == s[secondChange]
                and goal[secondChange] == s[firstChange];
        
    }
};