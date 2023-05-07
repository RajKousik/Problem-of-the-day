class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) 
    {
        int n = obstacles.size();
        vector<int> ans(n, 0);
        
        vector<int> lis;
        
        for(int i=0; i<n; i++)
        {
            int value = obstacles[i];
            
            int index;
            if(lis.size() == 0)
            {
                lis.push_back(value);
                index = 0;
            }
            else
            {
                index = upper_bound(lis.begin(), lis.end(), value) - lis.begin();
                if(index == lis.size())
                {
                    lis.push_back(value);
                }
                else
                {
                    lis[index] = value;
                }
            }
            ans[i] = 1 + index;
        }
        
        return ans;
        
    }
};