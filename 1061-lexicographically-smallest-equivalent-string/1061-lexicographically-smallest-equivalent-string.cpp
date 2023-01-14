class Solution {
public:
    vector<int> parent;
    
    
    int find(int x)
    {
        if(parent[x] == x)
        {
            return x;
        }
        
        return parent[x] = find(parent[x]);
    }
    
    void performUnion(int x, int y)
    {
        x = find(x);
        y = find(y);
        
        if(x == y)
        {
            return;
        }
        
        if(x < y)
        {
            parent[y] = x;
        }
        else
        {
            parent[x] = y;
        }
    }
    
    //union and find problem
    string smallestEquivalentString(string s1, string s2, string baseStr) 
    {
        
        parent = vector<int>(26, 0);
        
        for(int i=0; i<26; i++)
        {
            parent[i] = i;
        }
        
        int size = s1.size();
        //both are same size
        //int size = s2.size();
        
        for(int i=0; i<size; i++)
        {
            performUnion(s1[i] - 'a', s2[i] - 'a');
        }
        
        string ans = "";
        for(int i=0; i<baseStr.size(); i++)
        {
            ans += (char)(find(baseStr[i] - 'a') + 'a');
        }
        
        return ans;
        
    }
};