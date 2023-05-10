class Solution {
public:
    bool check(vector<int>& nums) {
        
        //what we can do is :
        // if all arr[i] <= arr[i+1], then the array is already sorted
        
        //but there can be one instance where arr[i] > arr[i+1], becuase of the rotation
        
        //if there is more than one instance where arr[i] > arr[i+1], then it is false
        
        //as the array is sorted, we also have to compare, last element and first element so include that too i.e (arr[i] > arr[(i+1) % arr.size])
        
        int noOfTimes = 0;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            
            if(nums[i] > nums[(i+1) % n])
            {
                noOfTimes++;
            }
            
            if(noOfTimes > 1)
            {
                return false;
            }
            
        }
        
        return true;
        
        
    }
};