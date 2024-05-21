class Solution {
public:
    int numberOfCleanRooms(vector<vector<int>>& room) {
        const vector<int> directions{0, 1, 0, -1, 0};
        int row = 0, col = 0, cleaned = 0, direction = 0;
        int rows = room.size(), cols = room[0].size();
        
        // Clean until we revisit a space facing the same direction
        while (!(room[row][col] >> (direction + 1) & 1)){
            // If the robot hasn't cleaned this space yet, increment cleaned
            if (room[row][col] == 0)
                ++cleaned;
            
            // Mark the room as visited facing this direction
            room[row][col] |= 1 << (direction + 1);
            
            // Clean the next space straight ahead if it's empty and in the room.
            int nextRow = row + directions[direction], nextCol = col + directions[direction + 1];
            
            if (0 <= nextRow && nextRow < rows && 0 <= nextCol && nextCol < cols && room[nextRow][nextCol] != 1){
                row = nextRow; col = nextCol;
            }
            else{
                // Otherwise turn right and clean the current space
                direction = (direction + 1) % 4;
            }
            
        }
        
        return cleaned;
    }
};