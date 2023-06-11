class RecentCounter {
private:
    queue<int> data;
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        data.push(t);
        while(data.front() < t - 3000)
        {
            data.pop();
        }
        return data.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */