class Solution {
    bool feasible(vector<int>& weights, int capacity, int days){
        int daysNeeded = 1, currentLoad = 0;
        
        for (int weight : weights){
            currentLoad += weight;
            if (currentLoad > capacity){
                currentLoad = weight;
                ++daysNeeded;
            }
        }
        return daysNeeded <= days;
    }
    
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxLoad = 0, totalLoad = 0;
        for (int weight : weights){
            totalLoad += weight;
            maxLoad = max(maxLoad, weight);
        }
        
        int l = maxLoad, r = totalLoad, mid;
        
        while (l < r){
            mid = (l + (r - l) / 2);
            if (feasible(weights, mid, days)) r = mid;
            else l = mid + 1;
        }
        
        return l;
    }
};