class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) 
    {
        int n = profits.size();
        vector<pair<int, int>> projects(n);
        
        for(int i=0; i<n; i++)
        {
            projects[i] = {capital[i], profits[i]};
        }
        
        sort(projects.begin(), projects.end());
        
        priority_queue<int> q;
        
        int ptr = 0;
        
        while(k--)
        {
            while(ptr < n and projects[ptr].first <= w)
            {
                q.push(projects[ptr].second);
                ptr++;
            }
            
            if(q.empty())
            {
                break;
            }
            
            w += q.top();
            q.pop();
            
        }
        
        return w;
        
    }
};