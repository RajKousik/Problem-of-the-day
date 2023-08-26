class Solution {
public:
    
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        
        sort(pairs.begin(), pairs.end(), comp);
        
        int ans = 1, n = pairs.size();
        vector<int> last = pairs[0];
        for(int i=1; i<n; i++)
        {
            if(last[1] < pairs[i][0])
            {
                ans++;
                last = pairs[i];
            }
        }
        
        return ans;
        
    }
};