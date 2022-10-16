class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();
        
        //if only one number is present, return as it is
        if(n <= 1)
        {
            return;
        }
        
        int i, j;
        
        //find the position where the transformation must be done
        for(i = n-2; i>=0; i--)
        {
            if(nums[i] < nums[i+1])
            {
                break;
            }
        }
        
        // if it below 0, reverse the whole array 
        if(i < 0)
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {   //find the number whoch should be swapped with that number
            for(j = n-1; j>i; j--)
            {
                if(nums[j] > nums[i])
                {
                    break;
                }
            }
            
            //swap both numbers
            swap(nums[i], nums[j]);
            
            //reverse it to get the array
            reverse(nums.begin() + i + 1, nums.end());
        }
        
        
        //example - [1,3,5,4,2]
        // i=1
         // j = 3
        // swap -> [1,4,5,3,2]
        //reverse -> [1,4,2,3,5]
        
    }
};