class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        
        int n = arr.size();
        int low = 0;
        int high = n-1;
        
        while(low < high)
        {
            int mid = (low + high)/2;
            
            if((mid % 2 == 0 and arr[mid]==arr[mid+1] ) or (mid % 2 == 1 and arr[mid] == arr[mid-1]))
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
            
        }
        return arr[low];
        
    }
};