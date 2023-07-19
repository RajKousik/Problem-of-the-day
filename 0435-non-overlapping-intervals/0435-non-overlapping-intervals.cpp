class Solution {
public:
    
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int ans = 0;
        
        sort(intervals.begin(),intervals.end(), comp);
        vector<int> temp = intervals[0];
        
        for(int i=1; i<n; i++)
        {
            if(intervals[i][0] < temp[1])
            {
                ans++;
            }
            else
            {
                temp = intervals[i];
            }   
        }
        return ans;
    }
};