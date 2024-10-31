typedef long long ll;

class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        // Sort robots and factoris by position
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        
        // Flatten factory positions according to their capacities
        vector<int> factoryPositions;
        for (const auto& f: factory)
            for (int i = 0; i < f[1]; ++i) factoryPositions.push_back(f[0]);
        
        int robotCount = robot.size(), factoryCount = factoryPositions.size();
        vector<ll> prevDp(factoryCount + 1), dp(factoryCount + 1);
        
        // Fill dp table using two rows for optimization
        for (int i = robotCount - 1; i >= 0; --i){
            // No factories left case
            if (i != robotCount - 1)
                prevDp.back() = 1e12;
            
            // Initialize current row
            dp.back() = 1e12;
            for (int j = factoryCount - 1; j >= 0; --j){
                // Assign current robot to current factory
                ll assign = abs(robot[i] - factoryPositions[j]) + prevDp[j + 1];
                
                // Skip current factory for this robot
                ll skip = dp[j + 1];
                
                // Take the minimum option
                dp[j] = min(assign, skip);
            }
            
            // Move to next robot
            prevDp = dp;
        }
        
        // Return minimum distance starting from the first robot
        return prevDp[0];
    }
};