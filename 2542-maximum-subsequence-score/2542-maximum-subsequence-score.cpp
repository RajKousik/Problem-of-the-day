class Solution {
    
    static bool comp(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second > b.second;
    }
    
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int n = nums1.size();
        
        vector<pair<int, int>> pairs(n);
        
        for(int i=0; i<n; i++)
        {
            pairs[i] = {nums1[i], nums2[i]};
        }
        
        sort(pairs.begin(), pairs.end(), comp);
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        long long topKSum = 0;
        
        for(int i=0; i<k; i++)
        {
            topKSum += (long long)pairs[i].first;
            pq.push(pairs[i].first);
        }
        
        long long answer = topKSum * pairs[k-1].second;
        
        for(int i=k; i<n; i++)
        {
            topKSum += (pairs[i].first - pq.top());
            pq.pop();
            pq.push(pairs[i].first);

            
            answer = max(answer, topKSum * pairs[i].second);
        }
        
        return answer;
        
    }
};