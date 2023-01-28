class SummaryRanges {
    set<int> st;
public:
    
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals()
    {
        if(st.empty())
        {
            return {};
        }
        
        vector<vector<int>> ans;
        int left = -1;
        int right = -1;
        
        for(auto value : st)
        {
            if(left < 0)
            {
                left = right = value;
            }
            else if(value == right + 1)
            {
                right = value;
            }
            else
            {
                ans.push_back({left, right});
                left = right = value;
            }
        }
        ans.push_back({left, right});
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */