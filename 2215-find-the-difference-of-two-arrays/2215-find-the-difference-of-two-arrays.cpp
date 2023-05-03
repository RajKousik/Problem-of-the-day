class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2)
    {
        
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        
        
        vector<vector<int>> ans(2);
        
        set<int> unique;
        for(auto it : nums1)
        {
            if(s2.find(it) == s2.end())
            {
                // ans[0].push_back(it);
                unique.insert(it);
            }
        }
        
        vector<int> firstAns(unique.begin(), unique.end());
        unique.clear();
        
        for(auto it : nums2)
        {
            if(s1.find(it) == s1.end())
            {
                unique.insert(it);
            }
        }
        vector<int> secondAns(unique.begin(), unique.end());
        return {firstAns, secondAns};
        
    }
};