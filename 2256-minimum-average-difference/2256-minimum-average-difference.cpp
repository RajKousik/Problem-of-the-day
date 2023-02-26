class Solution {
public:
    int minimumAverageDifference(vector<int>& arr) {
        
        int n = arr.size();
        
        vector<long long int> prefixSum(n);
        prefixSum[0] = arr[0];
        long long int sum = arr[0];
        
        for(int i=1; i<n; i++)
        {
            sum += arr[i];
            prefixSum[i] = prefixSum[i-1] + arr[i];
        }
        
        int minDiff = INT_MAX;
        
        int ans;
        
        for(int i=0; i<n; i++)
        {
            long long int sum1 = prefixSum[i];
            long long int sum2 = sum - prefixSum[i];
            
            int t1 = sum1 / (i+1);
            
            int t2 = 0;
            if(n-i-1 != 0)
                t2 = sum2 / (n-i-1);
            
            int currDiff = abs(t1 - t2);
            // cout<<currDiff<<" ";
            if(currDiff < minDiff)
            {
                minDiff = currDiff;
                ans = i;
            }
            
        }
        
        return ans;
        
    }
};