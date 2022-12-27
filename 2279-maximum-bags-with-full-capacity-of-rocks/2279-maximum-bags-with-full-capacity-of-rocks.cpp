class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        
        int n = capacity.size();
        vector<int> diff(n);
        
        for(int i=0; i<n; i++)
        {
            diff[i] = capacity[i] - rocks[i];
        }
        
        sort(diff.begin(), diff.end());
        
        int bags = 0;
        for(int i=0; i<n; i++)
        {
            if(diff[i] <= additionalRocks)
            {
                additionalRocks -= diff[i];
                bags++;
            }
        }
        
        return bags;
        
    }
};