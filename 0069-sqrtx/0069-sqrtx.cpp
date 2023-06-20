class Solution {
public:
    int mySqrt(int x) {
        
        if(x == 0) return 0;
        
        int low = 1, high = x, ans=-1;
        
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            // mid * mid == x overflows
            if(mid == x / mid)
            {
                return mid;
            }
            else if(mid > x / mid)
            {
                high = mid - 1;
            }
            else
            {
                ans = mid;
                low = mid + 1;
            }
            
        }
        
        return ans;
        
    }
};