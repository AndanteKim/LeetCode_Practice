class UndergroundSystem {
    unordered_map<int, pair<string, int>> checkInData;
    unordered_map<string, pair<int, int>> journeyData;
    
public:
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        checkInData[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string startStation = checkInData[id].first;
        int startTime = checkInData[id].second;
        checkInData.erase(id);
        
        journeyData[boundFor(startStation, stationName)].first += t - startTime;
        ++journeyData[boundFor(startStation, stationName)].second;
    }
    
    double getAverageTime(string startStation, string endStation) {
        double totalTime = (double)journeyData[boundFor(startStation, endStation)].first;
        int totalTrips = journeyData[boundFor(startStation, endStation)].second;
        return totalTime / totalTrips;
    }
    
    string boundFor(string& startStation, string& endStation){
        return startStation + " -> " + endStation;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */