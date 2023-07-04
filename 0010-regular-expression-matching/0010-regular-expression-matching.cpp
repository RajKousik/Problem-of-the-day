class Solution {
private:
    bool checkForAllStars(string s, int index)
    {
        for(int i=0; i<=index; i++)
        {
            if(s[i] != '*') return false;
        }
        return true;
    }
    
    bool dfs(int i, int j, string s, string p)
    {
        if(i < 0 and j < 0)
        {
            return 1;
        }
        if(j < 0 and i >= 0)
        {
            return 0;
        }
         if (i < 0 && j >= 0) //number of remaining chars should be even & half of them should be *, so it can be mapped to empty string
        {
            int count = 0, len = j + 1;
            if (len & 1) return false;
            while (j >= 0)
            {
                if (p[j--] == '*') count++;
            }

            return count == len / 2;
        }
        
        if(s[i] == p[j] or p[j] == '.')
        {
            return dfs(i-1, j-1, s, p);
        }
        else
        {
            if(p[j] == '*')
            {
                return dfs(i, j - 2, s, p) or ((s[i] == p[j - 1] or p[j - 1] == '.') && dfs(i - 1, j, s, p));
            }
            else
            {
                return 0;
            }
        }
        return 0;
    }
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        return dfs(m-1, n-1, s, p);
    }
};