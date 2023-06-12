class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        int start, end;
        
        int n = nums.size();
        
        vector<string> ans;
        
        for(int i=0; i<n; i++)
        {
            start = nums[i];
            
            while(i+1 < n and nums[i] + 1 == nums[i+1])
            {
                i++;
            }
            
            end = nums[i];
            
            if(start == end)
            {
                ans.push_back(to_string(start));
            }
            else
            {
                string temp = to_string(start) + "->" + to_string(end);
                ans.push_back(temp);
            }
            
        }
        
        return ans;
        
    }
};