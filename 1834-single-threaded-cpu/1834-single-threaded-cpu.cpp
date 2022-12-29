class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        
        int n = tasks.size();
        
        for(int i=0; i<n; i++)
        {
            tasks[i].push_back(i);
        }
        
        sort(tasks.begin(), tasks.end());
        
        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

        long long currTime = 0;
        int index = 0;
        
        vector<int> ans;
        
        while(index < n or !pq.empty())
        {
            if(pq.empty())
            {
                currTime = max(currTime, (long long)tasks[index][0]);
            }
            
            while(index < n and tasks[index][0] <= currTime)
            {
                pq.push( { tasks[index][1], tasks[index][2] } );
                index++;
            }
            
            auto node = pq.top();
            pq.pop();
            
            int proccesTimeOfTask = node.first;
            int indexOfTask = node.second;
            
            currTime += proccesTimeOfTask;
            ans.push_back(indexOfTask);
            
            
        }
        return ans;
        
    }
};