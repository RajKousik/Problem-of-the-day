class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int insertPosition = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(i+1<n && nums[i]==nums[i+1]){
                continue;
            }
            nums[insertPosition] = nums[i];
            insertPosition++;
        }
        return insertPosition;
    }
};