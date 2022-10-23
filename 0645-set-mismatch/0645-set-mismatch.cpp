class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> freq(n+1, 0);
        
        for(auto it : nums)
        {
            freq[it]++;
        }
        
        int dup=-1, miss=-1;
        for(int i=0; i<nums.size(); i++)
        {
            if(freq[i+1] == 2)
            {
                dup = i+1;
            }
            else if(freq[i+1] == 0)
            {
                miss = i+1;
            }
        }
        
        return {dup, miss};
        
    }
};