class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        
        priority_queue<int, vector<int>, greater<int> > firstWorkers, lastWorkers;
        
        int n = costs.size();
        
        for(int i=0; i<candidates; i++)
        {
            firstWorkers.push(costs[i]);
        }
        
        for(int i=max(n-candidates, candidates); i < n; i++)
        {
            lastWorkers.push(costs[i]);
        }
        
        int firstPtr = candidates;
        int lastPtr = n - candidates - 1;
        
        long long answer = 0;
        
        for(int i=0; i<k; i++)
        {
            if(lastWorkers.empty() || (!firstWorkers.empty() && firstWorkers.top() <= lastWorkers.top() ) )
            {
                
                answer += firstWorkers.top();
                cout<<firstWorkers.top()<<endl;
                firstWorkers.pop();
                
                if(firstPtr <= lastPtr)
                {
                    firstWorkers.push(costs[firstPtr]);
                    firstPtr++;
                }
                
            }
            else
            {
                answer += lastWorkers.top();
                cout<<lastWorkers.top()<<endl;
                lastWorkers.pop();
                
                if(firstPtr <= lastPtr)
                {
                    lastWorkers.push(costs[lastPtr]);
                    lastPtr--;
                }
            }
        }
        
        return answer;
        
    }
};