class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int nextIdleTime = 0, n = customers.size();
        double netWaitTime = 0.0;
        
        for (auto& customer : customers){
            // The next idle time for the chef is given by the time of delivery
            // of current customer's order.
            nextIdleTime = max(nextIdleTime, customer[0]) + customer[1];
            
            // The wait time for the current customer is the difference between
            // his delivery time and arrival time.
            netWaitTime += nextIdleTime - customer[0];
        }
        
        // Divide by total customers to get average.
        double averageWaitTime = netWaitTime / n;
        return averageWaitTime;
    }
};