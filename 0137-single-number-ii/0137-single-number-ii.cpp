class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int ans = 0, countOdd = 0, countEven = 0;
        //building the ans, bit by bit
        
        for(int i=0; i<32; i++)
        {
            countOdd = 0, countEven = 0;
            for(int j=0; j<nums.size(); j++)
            {
                if((nums[j] & (1 << i)) != 0) //then it is 1 bit number
                {
                    countOdd++;
                }
                else
                {
                    countEven++;
                }
            }
            if(countOdd % 3)
            {
                ans = ans | (1 << i);   
            }
            else
            {
                ans = ans | (0 << i);
            }
        }
        return ans;
        
    }
};