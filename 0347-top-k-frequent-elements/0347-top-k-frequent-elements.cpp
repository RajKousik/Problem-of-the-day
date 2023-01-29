class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int num : nums){
            map[num]++;
        }
        
        vector<int> res;
        // pair<first, second>: first is frequency,  second is number
        int n = map.size() - k;
        priority_queue<pair<int,int>> pq; 
        for(auto it : map){
            pq.push({it.second, it.first});
            if(pq.size() > n){
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
    }
};