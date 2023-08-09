class Solution {

private:
    bool isPossible(int value, vector<int> &nums, int pairsNeeded)
    {
        int pairs = 0;
        
        for(int i=1; i<nums.size(); i++)
        {
            
            if(nums[i] - nums[i-1] <= value)
            {
                pairs++;
                i++;
            }
            
        }
        
        return pairs >= pairsNeeded;
        
    }
    
    
public:
    int minimizeMax(vector<int>& nums, int p) {
        
        int ans=-1, n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        int low = 0;
        int high = nums[n-1] - nums[0];
        
        
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            cout<<low<<" "<<high<<" "<<mid<<endl;
            if(isPossible(mid, nums, p))
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