typedef long long ll;

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        ll left = 1, right = totalTrips * (ll)*max_element(time.begin(), time.end());
        
        while (left < right){
            ll mid = left + ((right - left) >> 1), trips = 0;
            for (int t : time) trips += mid / t;
            if (totalTrips <= trips) right = mid;
            else left = mid + 1;
        }
        
        return left;
    }
};