class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if (dist.size() > ceil(hour)) return -1;
        
        int left = 1, right = pow(10, 7);
        while (left <= right){
            int mid = left + (right - left) / 2;
            double time = 0.0;
            
            for (double d : dist){
                time = ceil(time);
                time += d / mid;
            }
            
            if (time <= hour) right = mid - 1;
            else left = mid + 1;
        }
        
        return left;
    }
};