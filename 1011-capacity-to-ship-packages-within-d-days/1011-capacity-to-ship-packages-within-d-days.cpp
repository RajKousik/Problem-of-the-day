class Solution {
private:
    
    bool isValid(vector<int>& weights, int capacity, int days, int n)
    {
        int sum = weights[0];
        int count = 1;
        
        for(int i=1; i<n; i++)
        {
            if(sum + weights[i] <= capacity)
            {
                sum += weights[i];
            }
            else
            {
                sum = weights[i];
                count++;
            }
        }
        
        return count <= days;
    }
    
public:
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int n = weights.size();
        
        int mini = INT_MIN;
        int sum = 0;
        
        for(int i=0; i<n; i++)
        {
            sum += weights[i];
            mini = max(mini, weights[i]);
        }
        
        int low = mini;
        int high = sum;
        
        int ans;
        
        while(low <= high)
        {
            int mid = (low + high)/2;
            
            if(isValid(weights, mid, days, n))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        
        return ans;
        
    }
};