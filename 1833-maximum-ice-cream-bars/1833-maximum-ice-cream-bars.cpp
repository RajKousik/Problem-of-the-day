class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        
        sort(costs.begin(), costs.end());
        
        int i = 0;
        int n = costs.size();
        
        int ans = 0;
        while(i < n)
        {
            if(coins >= costs[i])
            {
                ans++;
                coins -= costs[i];
            }
            else
            {
                break;
            }
            i++;
        }
        
        return ans;
        
    }
};