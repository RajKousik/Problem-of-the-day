class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, int> umap;
        int nonDuplicateIndex = 0;
        // umap[nums[0]]++;
        for(int i=0; i<nums.size(); i++)
        {
            if(umap[nums[i]] < 2)
            {
                nums[nonDuplicateIndex++] = nums[i];
            }
            umap[nums[i]]++;
        }
        return nonDuplicateIndex;
        
    }
};