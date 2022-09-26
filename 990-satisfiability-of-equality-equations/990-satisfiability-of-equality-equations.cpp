class Solution {
public:
    
    int findParent(int ch, vector<int> &parent)
    {
        return parent[ch] == ch ? ch : findParent(parent[ch], parent);
    }
    
    bool equationsPossible(vector<string>& equations) 
    {
        vector<int> parent(26, 0);
        
        for(int i=0; i<26; i++)
        {
            parent[i] = i;
        }
        
        for(auto str : equations)
        {
            if(str[1] == '=')
            {
                int x = findParent(str[0]-'a', parent);
                int y = findParent(str[3]-'a', parent);
                
                if(x != y)
                {
                    parent[y] = x;
                }
              
            }
        }
        
        for(auto str : equations)
        {
            if(str[1] == '!')
            {
                int x = findParent(str[0]-'a', parent);
                int y = findParent(str[3]-'a', parent);
                
                if(x == y)
                {
                    return false;
                }
              
            }
        }
        
        return true;
    }
};