class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        if (time.size() == 1) return 1LL * totalTrips * time[0];
        
        long long left = 1, right = 1LL * totalTrips * *min_element(time.begin(), time.end()), mid, actual_trips;
        
        while (left < right){
            actual_trips = 0;
            mid = left + (right - left) / 2;
            for (int t : time){
                actual_trips += mid / t;
            }
            
            if (actual_trips >= totalTrips) right = mid;
            else left = mid + 1;
        }
        
        return left;
    }
};