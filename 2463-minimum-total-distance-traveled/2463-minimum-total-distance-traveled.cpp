class Solution {
private:
    int robotCount, factoryCount;
    const long long mx = 1e12;
    long long dp(int robotIndex, int factoryIndex, vector<int>& robot, vector<int>& factoryPositions, vector<vector<long long>>& memo){
        // Check memo
        if (memo[robotIndex][factoryIndex] != -1)
            return memo[robotIndex][factoryIndex];
        
        // All robots assigned
        if (robotIndex == robotCount) return memo[robotIndex][factoryIndex] = 0;
        
        // No factories left to assign
        if (factoryIndex == factoryCount) return memo[robotIndex][factoryIndex] = mx;
        
        // Option 1: Assign current robot to current factory
        long long assign = abs(robot[robotIndex] - factoryPositions[factoryIndex]) + dp(robotIndex + 1, factoryIndex + 1, robot, factoryPositions, memo);
        
        // Option 2: Skip current factory for the current robot.
        long long skip = dp(robotIndex, factoryIndex + 1, robot, factoryPositions, memo);
        
        // Take the minimum and store in memo.
        return memo[robotIndex][factoryIndex] = min(assign, skip);
    }
    
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        vector<int> factoryPositions;
        // Sort robots and factories by position
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        
        // Flatten factory positions according to their capacities
        for (const vector<int>& f : factory){
            for (int i = 0; i < f[1]; ++i)
                factoryPositions.push_back(f[0]);
        }
        this -> robotCount = robot.size(), this -> factoryCount = factoryPositions.size();
        vector memo(robotCount + 1, vector<long long>(factoryCount + 1, -1));
        
        // Recursively calculate minimum total distance with memoization
        return dp(0, 0, robot, factoryPositions, memo);
    }
};