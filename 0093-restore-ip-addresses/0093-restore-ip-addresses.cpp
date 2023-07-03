class Solution {
public:
    
    bool isValid(string temp)
    {
        if(temp.size() > 3 or temp.size() == 0)
        {
            return false;
        }
        if(temp.size() > 1 and temp[0] == '0')
        {
            return false;
        }
        if(stoi(temp) > 255)
        {
            return false;
        }
        return true;
    }
    
    void func(int index, int dots, string s, vector<string> &ans, string output)
    {
        
        if(dots == 3)
        {
            if(isValid(s.substr(index)))
            {
                ans.push_back(output + s.substr(index));
            }
            return;
        }
        
        int sz = s.size();
        for(int i=index; i < min(index+3, sz); i++)
        {
            if(isValid(s.substr(index, i-index+1)))
            {
                output.push_back(s[i]);
                output.push_back('.');
                func(i+1, dots+1, s, ans, output);
                output.pop_back();
            }
        }
        
        
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string temp = "";
        func(0, 0, s, ans, temp);
        return ans;
    }
};