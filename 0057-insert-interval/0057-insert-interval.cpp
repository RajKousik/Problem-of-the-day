class Solution {
    
private:
    
    bool isOverlapping(vector<int> &a, vector<int> &b)
    {
        return min(a[1],b[1]) - max(a[0],b[0]) >= 0;
    }
    
    vector<int> mergeIntervals(vector<int> &a, vector<int> &b)
    {
        return {min(a[0], b[0]), max(a[1], b[1])};
    }
    
    void insertInterval(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        
        auto index = upper_bound(intervals.begin(), intervals.end(), newInterval) - intervals.begin();
        
        if(index != intervals.size())
        {
            intervals.insert(intervals.begin() + index, newInterval);
        }
        else
        {
            intervals.push_back(newInterval);
        }
        
        
    }
    
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        insertInterval(intervals, newInterval);
        
        vector<vector<int>> ans;
        
        int n = intervals.size();
        
        for(int i=0; i<n; i++)
        {
            
            vector<int> currentInterval = intervals[i];
            
            while(i < n and isOverlapping(currentInterval, intervals[i]))
            {
                currentInterval = mergeIntervals(currentInterval, intervals[i]);
                i++;
            }
            
            i--;
            
            ans.push_back(currentInterval);
        }
        
        return ans;
        
    }
};