class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        
        sort(arr.begin(), arr.end());
        
        int prev = -1;
        int n = arr.size();
        for(int i=1; i<n; i++)
        {
            if(prev == -1)
            {
                prev = arr[i] - arr[i-1];
            }
            else if(arr[i] - arr[i-1] != prev)
            {
                return false;
            }
        }
        return true;
        
    }
};