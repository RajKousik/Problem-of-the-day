class Solution {
private:
    
    void dfs(int ind, vector<int> &cookies, int k, vector<int> &bucks, int &ans)
    {
        if(ind == cookies.size())
        {
            int maxEle = INT_MIN;
            for(int i=0; i<k; i++)
            {
                maxEle = max(maxEle, bucks[i]);
            }
            ans = min(ans, maxEle);
            return;
        }
        
        for(int i=0; i<bucks.size(); i++)
        {
            bucks[i] += cookies[ind];
            dfs(ind+1, cookies, k, bucks, ans);
            bucks[i] -= cookies[ind];
        }
        
    }
    
public:
    int distributeCookies(vector<int>& cookies, int k) {
        
        int n = cookies.size();
        vector<int> bucks(k, 0);
        int ans = INT_MAX;
        dfs(0, cookies, k, bucks, ans);
        return ans;
    }
};