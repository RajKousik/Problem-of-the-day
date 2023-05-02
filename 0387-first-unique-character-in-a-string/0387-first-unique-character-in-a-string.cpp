class Solution {
public:
    int firstUniqChar(string s) {
        int map[26]  = {0};

        for(int i=0; i<s.size(); i++)
        {
            map[s[i] - 'a']++; 
        }

        for(int i=0; i<s.size(); i++)
        {
            if(map[s[i] - 'a'] == 1)
            {
                return i;
            }
        }

        return -1;
    }
};