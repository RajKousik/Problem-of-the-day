class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        unordered_map<int, int> lostCount;
        
        for(auto p : matches)
        {
            int winner = p[0];
            int loser = p[1];
            
            if(lostCount.find(winner) == lostCount.end())
            {
                lostCount[winner] = 0;
            }
            lostCount[loser]++;
        }
        
        vector<vector<int>> ans(2, vector<int>());
        for(auto it : lostCount)
        {
            if(it.second == 0)
            {
                ans[0].push_back(it.first);
            }
            else if(it.second == 1)
            {
                ans[1].push_back(it.first);
            }
        }
        
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        
        return ans;
        
    }
};