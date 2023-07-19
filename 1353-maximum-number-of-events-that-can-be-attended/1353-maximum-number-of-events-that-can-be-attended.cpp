class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        
        priority_queue<int, vector<int>, greater<int> > pq;
        sort(events.begin(), events.end());
        
        int meetingsAttened = 0, i=0;
        int n = events.size();
        int currentDay = 0;
        
        while(!pq.empty() or i < n)
        {
            if(pq.size() == 0)
            {
                currentDay = events[i][0];        
            }
            
            while(i < n and events[i][0] <= currentDay)
            {
                pq.push(events[i][1]);
                i++;
            }
            pq.pop();
            meetingsAttened++;
            currentDay++;
            
            while(!pq.empty() and pq.top() < currentDay)
            {
                pq.pop();
            }

        }
        
        return meetingsAttened;
        
    }
};