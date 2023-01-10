class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int count = 0;
        int candidate;
        
        for(auto it : nums)
        {
            if(count == 0)
            {
                candidate = it;
                count++;
            }
            else if(it == candidate)
            {
                count++;
            }
            else
            {
                count--;
            }
            
        }
        
        return candidate;
        
    }
};