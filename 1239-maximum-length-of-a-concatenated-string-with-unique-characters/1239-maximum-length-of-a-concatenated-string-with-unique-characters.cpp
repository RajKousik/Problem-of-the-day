class Solution {
public:
    
    int solve(vector<string> &arr, string str, int index)
    {
        unordered_set<char> st(str.begin(), str.end());
        
        if(st.size() != str.size())
        {
            return 0;
        }
        
        int res = str.size();
        
        for(int i = index ; i< arr.size(); i++)
        {
            res = max(res, solve(arr, str+arr[i], i+1));
        }
        
        return res;
    }
    
    int maxLength(vector<string>& arr) {
        
        string str = "";
        int index = 0;
        return solve(arr, str, index);
        
    }
};