class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        if( n == 1) return 1;
        
        vector<int> counts(n+1, 0);
        
        for(auto it : trust)
        {
            counts[it[0]]--;
            counts[it[1]]++;
        }
        
        for(int i=0; i<=n; i++)
        {
            if(counts[i] == n-1)
            {
                return i;
            }
        }
        
        return -1;
        
    }
};