class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n = rooms.size();
        
        vector<int> vis(n, false);
        vis[0] = true;
        
        stack<int> st;
        st.push(0);
        
        while(!st.empty())
        {
            int curr = st.top();
            st.pop();
            
            for(auto nei : rooms[curr])
            {
                if(!vis[nei])
                {
                    vis[nei] = true;
                    st.push(nei);
                }
            }
        }
        
        
        
        
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                return false;
            }
        }
        
        return true;
        
    }
};