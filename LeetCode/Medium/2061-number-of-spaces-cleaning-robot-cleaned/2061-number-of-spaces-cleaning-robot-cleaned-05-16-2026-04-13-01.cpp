class Solution {
public:
    int numberOfCleanRooms(vector<vector<int>>& room) {
        int m = room.size(), n = room[0].size();
        int ans = 0, r = 0, c = 0, d = 0;
        int DIRS[] = {0, 1, 0, -1, 0};
        auto isValid = [&](int row, int col) -> bool {
            return 0 <= row && row < m && 0 <= col && col < n && room[row][col] != 1;
        };
        
        while (!((room[r][c] >> (d + 1)) & 1)) {
            if (room[r][c] == 0) ++ans;

            room[r][c] |= (1 << (d + 1));
            int newR = r + DIRS[d], newC = c + DIRS[d + 1];
            if (isValid(newR, newC)) {
                r = newR;
                c = newC;
            }
            else d = (d + 1) % 4;

        }

        return ans;
    }
};