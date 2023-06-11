class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        double maxiAns = 0;
        double temp = 0;
        for(int i=0; i<k; i++)
        {
            temp += (double)nums[i];
        }
        
        maxiAns = temp/k;
        
        int left = 0, right = k;
        
        while(right < nums.size())
        {
            temp += (double)nums[right];
            temp -= (double)nums[left];
            
            maxiAns = max(maxiAns, temp/k);
            right++;
            left++;
        }
        
        return maxiAns;
        
    }
};