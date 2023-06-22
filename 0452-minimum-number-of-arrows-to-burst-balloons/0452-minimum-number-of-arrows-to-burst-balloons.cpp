class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort(points.begin(), points.end());
        
        int endPoint = points[0][1];
        int ans = 1;
        
        for(auto it : points)
        {
            
            if(it[0] > endPoint)
            {
                ans++;
                endPoint = it[1];
            }
            else
                endPoint = min(endPoint, it[1]);
        }
        
        return ans;
        
    }
};