class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        int m = spells.size();
        int n = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> result(m, 0);
        
        for(int i=0; i<m; i++)
        {
            int spell = spells[i];
            int low = 0, high = n-1;
            int ans = 0;
            while(low <= high)
            {
                int mid = low + (high - low)/2;
                // cout<<mid<<" "<<spell * potions[mid]<<" ";
                long long product = (long long)spell * (long long)potions[mid];
                if(product >= success)
                {   
                    ans = (n - mid);
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            result[i] = ans;
        }
        return result;
    }
};