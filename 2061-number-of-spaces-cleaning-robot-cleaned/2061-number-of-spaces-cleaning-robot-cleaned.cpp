class Solution {
private:
    const vector<int> directions{0, 1, 0, -1, 0};
    int rows, cols;
    int clean(vector<vector<int>>& room, int row, int col, int direction, unordered_set<string>& visited, unordered_set<string>& cleaned){
        // If the robot already visited this space facing this direction
        // Return the number of spaces cleaned
        if (visited.find(to_string(row) + to_string(col) + to_string(direction)) != visited.end())
            return cleaned.size();
        
        // Mark the space as visited facing this direction and cleaned
        visited.insert(to_string(row) + to_string(col) + to_string(direction));
        cleaned.insert(to_string(row) + to_string(col));
        
        // Clean the next space straight ahead if it's empty and in the room
        int nextRow = row + directions[direction], nextCol = col + directions[direction + 1];
        
        if (0 <= nextRow && nextRow < rows && 0 <= nextCol && nextCol < cols && room[nextRow][nextCol] == 0)
            return clean(room, nextRow, nextCol, direction, visited, cleaned);
        
        // Otherwise turn right and clean the current space
        return clean(room, row, col, (direction + 1) % 4, visited, cleaned);
    }
    
public:
    int numberOfCleanRooms(vector<vector<int>>& room) {
        this -> rows = room.size(), this -> cols = room[0].size();
        unordered_set<string> visited, cleaned;
        
        return clean(room, 0, 0, 0, visited, cleaned);
    }
};