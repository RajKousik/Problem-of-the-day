class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int totalTime = 0;
        int currMaxTime;
        int currTotal;
        
        int l = 0;
        int r = 0;
        
        int n = colors.size(); //or neededTime.size();
        
        while(l < n and r < n)
        {
            
            currTotal = 0;
            currMaxTime = 0;
            
            while(r < n and colors[l] == colors[r])
            {
                currTotal += neededTime[r];
                currMaxTime = max(currMaxTime, neededTime[r]);
                r++;
            }
            
            totalTime += currTotal - currMaxTime;
            l = r;
            
        }
        
        return totalTime;
        
    }
};