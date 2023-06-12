class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n = rooms.size();
        
        vector<bool> vis(n, false);
        vis[0] = true;
        
        queue<int> q;
        q.push(0);
        
        
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            
            for(auto it : rooms[node])
            {
                if(!vis[it])
                {
                    q.push(it);
                    vis[it] = true;
                }
            }
            
        }
        
        for(int i=0; i<n; i++)
        {
            if(!vis[i]) return false;
        }
        return true;
        
    }
};