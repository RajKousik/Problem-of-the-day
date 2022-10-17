class Solution {
public:
    bool checkIfPangram(string sentence) {
        
        set<char> st;
        
        for(auto c : sentence)
        {
            st.insert(c);
        }
        
        return st.size() == 26;
        
    }
};