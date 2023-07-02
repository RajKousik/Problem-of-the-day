class Solution {

private:
    void dfs(int index, int countOfRequests, vector<int> &inDegree, vector<vector<int>>& requests, int &ans, int n)
    {
        if(index == requests.size())    // n is not equal to requests.size()
        {
            for(int i=0; i<n; i++)
            {
                if(inDegree[i])
                {
                    return;
                }
            }
            // cout<<ans<<" ";
            ans = max(ans, countOfRequests);
            return;
        }
        
        inDegree[requests[index][0]]--;
        inDegree[requests[index][1]]++;
        
        dfs(index+1, countOfRequests+1, inDegree, requests, ans, n);
        
        inDegree[requests[index][0]]++;
        inDegree[requests[index][1]]--;
        
        dfs(index+1, countOfRequests, inDegree, requests, ans, n);
        
    }
    
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        
        vector<int> inDegree(n, 0);
        
        int ans = 0;
        
        dfs(0, 0, inDegree, requests, ans, n);
        
        return ans;
    }
};