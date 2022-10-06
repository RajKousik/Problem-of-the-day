class TimeMap {
public:
    
    unordered_map <string, unordered_map< int, string > > mp;
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        
        mp[key][timestamp]= value;
        
    }
    
    string get(string key, int timestamp) {
        
        if(mp.find(key) == mp.end() or timestamp == 0)
        {
            return "";
        }
        
        if(mp[key].find(timestamp) != mp[key].end())
        {
            return mp[key][timestamp];
        }
        else
        {
            return get(key, timestamp-1);
        }
        
        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */