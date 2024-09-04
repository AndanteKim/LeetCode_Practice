class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // Change data structure
        unordered_set<string> lookup;
        for (vector<int>& obstacle : obstacles){
            lookup.insert(to_string(obstacle[0]) + " " + to_string(obstacle[1]));
        }
        
        // Directions: North, East, South, West
        vector<pair<int, int>> directions {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int currTurn = 0, maxDist = 0;
        pair<int, int> currCoordinates{0,0};
        
        for (int command : commands){
            if (command == -1){
                currTurn = (currTurn + 1) % 4;
                continue;
            }
            else if (command == -2){
                currTurn = (currTurn - 1 + 4) % 4;
                continue;
            }
            else{
                // If we'll meet the obstacles, then updated it to sign there's an obstacle.
                bool updated = false;
                
                for (int k = 1; k <= min(command, 9); ++k){
                    if (lookup.count(to_string(currCoordinates.first + directions[currTurn].first * k) + " " + to_string(currCoordinates.second + directions[currTurn].second * k))){
                        if (directions[currTurn].first == 1)
                            currCoordinates.first += directions[currTurn].first * k - 1;
                        else if (directions[currTurn].first == -1)
                            currCoordinates.first += directions[currTurn].first * k + 1;
                        else if (directions[currTurn].second == 1)
                            currCoordinates.second += directions[currTurn].second * k - 1;
                        else
                            currCoordinates.second += directions[currTurn].second * k + 1;
                        updated = true;
                        break;
                    }
                }
                
                if (!updated){
                    // Update the coordinates to move
                    currCoordinates.first += directions[currTurn].first * command;
                    currCoordinates.second += directions[currTurn].second * command;
                }
                
                maxDist = max(maxDist, currCoordinates.first * currCoordinates.first + currCoordinates.second * currCoordinates.second);
            }
        }
        
        return maxDist;
    }
};