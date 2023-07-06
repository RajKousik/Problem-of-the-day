class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        
        int n = s.size();
        vector<string> ans;
        for(int i=0; i<n; i+=k)
        {
            if(i+k <= n)
            {
                ans.push_back(s.substr(i, k));
            }
            else
            {
                int rem = n - i;
                string res = s.substr(i);
                // k-=rem;
                cout<<k<<" ";
                for(int j=0; j<k-rem; j++)
                {
                    res += fill;
                }
                ans.push_back(res);
            }
        }
        return ans;
    }
};