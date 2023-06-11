class Solution {
public:
    int maxOperations(vector<int>& nums, int k)
    {
        unordered_map<int, int> umap;
        
        int answer = 0;
        for(int i=0; i<nums.size(); i++)
        {
            int x = k - nums[i];
            
            if(umap.find(x) != umap.end())
            {
                answer++;
                if(umap[x] == 1)
                {
                    umap.erase(x);
                }
                else
                {
                    umap[x]--;
                }
            }
            else
            {
                umap[nums[i]]++;
            }
            
        }
        
        return answer;
        
    }
};