class UndergroundSystem 
{
private:
    
    unordered_map< int, pair<string, int> > checkIns;
    unordered_map< string, pair< double, int> > statsInfo;
    
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) 
    {
        checkIns[id] = {stationName, t};    
    }
    
    void checkOut(int id, string stationName, int t) 
    {
        auto checkInInfo = checkIns[id];

        
        string newPath = checkInInfo.first + "->" + stationName;
        
        statsInfo[newPath].first += (t - checkInInfo.second);
        statsInfo[newPath].second += 1;
        
    }
    
    double getAverageTime(string startStation, string endStation) 
    {
        auto info = statsInfo[startStation + "->" + endStation];
        return (info.first/info.second);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */