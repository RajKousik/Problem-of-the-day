class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB)
    {
        int canA = capacityA;
        int canB = capacityB;
        
        int i = 0;
        int j = plants.size() - 1;
        
        int ans = 0;
        
        while(i <= j)
        {
            if(i == j)
            {
                if(max(canA, canB) < plants[i])
                {
                    ans++;
                }
                return ans;
            }
            
            if(canA >= plants[i])
            {
                canA -= plants[i];
            }
            else
            {
                ans++;
                canA = capacityA;
                canA -= plants[i];
            }
            
            if(canB >= plants[j])
            {
                canB -= plants[j];
            }
            else
            {
                ans++;
                canB = capacityB;
                canB -= plants[j];
            }
            
            i++;
            j--;
            
        }
        return ans;
    }
};