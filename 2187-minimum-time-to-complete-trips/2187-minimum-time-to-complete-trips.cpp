class Solution {
    bool timeEnough(vector<int>& time, long long given_time, int totalTrips){
        long long actual_trips = 0;
        for (int t : time){
            actual_trips += given_time / t;
        }
        
        return actual_trips >= totalTrips;
    }
    
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long left = 1, right = 2LL * *max_element(time.begin(), time.end()) * totalTrips, mid;
        
        while (left < right){
            mid = left + (right - left) / 2;
            
            if (timeEnough(time, mid, totalTrips)){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        
        return left;
    }
};