class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int> st;
        for(int asteroid : asteroids)
        {
            bool isCollided = false;
            while(!st.empty() and (st.top() >0 and asteroid < 0))
            {
                if( abs(st.top()) < abs(asteroid) )
                {
                    st.pop();
                }
                else
                {
                    if(abs(st.top()) == abs(asteroid))
                    {
                        st.pop();
                    }
                    isCollided = true;
                    break;
                }
            }
            if(!isCollided)
            {
                st.push(asteroid);
            }
        }
        
        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};