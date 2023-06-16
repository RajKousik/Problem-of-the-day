class Solution {

private:
    
    void dfs(int index, string temp, string &digits, vector<string> &ans, vector<string> &umap)
    {
        
        if(index == digits.size())
        {
            ans.push_back(temp);
            return;
        }
            

        for(int i=0; i<umap[digits[index]-'0'].size() ; i++)
        {
            temp.push_back(umap[digits[index]-'0'][i]);
            dfs(index+1, temp, digits, ans, umap);
            temp.pop_back();
        }
        
    }

public:
    vector<string> letterCombinations(string digits) 
    {
        
        if(digits.size() == 0) return {};
        
        // unordered_map<char, string> umap;
        // umap['2'] = "abc";
        // umap['3'] = "def";
        // umap['4'] = "ghi";
        // umap['5'] = "jkl";
        // umap['6'] = "mno";
        // umap['7'] = "pqrs";
        // umap['8'] = "tuv";
        // umap['9'] = "wxyz";
        
        vector<string> umap = {"", "", "abc", "def", "ghi", "jkl",
                                 "mno", "pqrs", "tuv", "wxyz"};
        
             
        vector<string> ans;
             
        dfs(0, "", digits, ans, umap);
        
        return ans;
    }
};