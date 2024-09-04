class Solution {
private:
    // Slightly larger than 2 * max values. 
    static const int HASH_MULTIPLIER = 60001;
    
    // Hash function to convert (x, y) coordinates to a unique integer value
    int hashCoordinates(int x, int y){
        return x * HASH_MULTIPLIER + y;
    }
    
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // Store obstacles in an unordered_set for efficient lookup
        unordered_set<int> obstacleSets;
        for (const auto& obstacle : obstacles){
            obstacleSets.insert(hashCoordinates(obstacle[0], obstacle[1]));
        }
        
        // Define direction vectors: North, East, South, West
        vector<pair<int, int>> directions {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        // 0: North, 1: East, 2: South, 3: West
        int maxDistSquared = 0, currDir = 0;
        int x = 0, y = 0;
        
        for (int command : commands){
            // Turn right
            if (command == -1){
                currDir = (currDir + 1) % 4;
                continue;
            }
            
            // Turn left
            if (command == -2){
                currDir = (currDir + 3) % 4;
                continue;
            }
            
            int dx = directions[currDir].first, dy = directions[currDir].second;
            
            // Move forward
            for (int i = 0; i < command; ++i){
                int newX = x + dx, newY = y + dy;
                
                if (obstacleSets.count(hashCoordinates(newX, newY)))
                    break;
                x = newX, y = newY;
            }
            maxDistSquared = max(maxDistSquared, x * x + y * y);
        }
        
        return maxDistSquared;
    }
};