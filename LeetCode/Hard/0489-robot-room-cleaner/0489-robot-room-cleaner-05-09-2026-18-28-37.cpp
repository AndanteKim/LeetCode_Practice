/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
private:
    struct HashPair {
        size_t operator()(const pair<int, int>& p) const {
            return hash<long long>()(((long long)p.first << 32) | (p.second & 0xFFFFFFFFLL));
        }
    };

    // Go clockwise: 0 - "up", 1 - "right", 2 - "down", 3 - "left"
    vector<pair<int, int>> directions{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    unordered_set<pair<int, int>, HashPair> visited;

    void goBack(Robot& robot) {
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }

    void backtrack(Robot& robot, pair<int, int> cell = {0, 0}, int d = 0) {
        visited.insert(cell);
        robot.clean();

        for (int i = 0; i < 4; ++i) {
            int newD = (d + i) % 4;
            pair<int, int> newCell = {cell.first + directions[newD].first,
                                      cell.second + directions[newD].second};
            if (!visited.contains(newCell) && robot.move()) {
                backtrack(robot, newCell, newD);
                goBack(robot);
            }
            robot.turnRight();
        }
    }   

public:
    void cleanRoom(Robot& robot) {
        backtrack(robot);
    }
};