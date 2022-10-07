class MyCalendarThree {
    
    private:
        
        map<int, int> mp;
        int res = 0;
    
public:
    

    
    MyCalendarThree() {
        
        mp[0] = 0;
        mp[1e9+1] = 0;
        
    }
    
    void split(int x)
    {
        mp[x] = (--(mp.upper_bound(x)) )->second;
    }
    
    int book(int start, int end) {
        
        split(start);
        split(end);
        
        for(auto it = mp.find(start); it->first < end; it++)
        {
            res = max(res, ++(it->second));
        }
        
        return res;
        
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */