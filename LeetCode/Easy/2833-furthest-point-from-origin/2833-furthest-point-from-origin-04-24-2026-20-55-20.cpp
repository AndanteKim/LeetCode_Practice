class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int ans = 0;
        vector<int> dirs(2, 0);

        for (const char& c : moves) {
            if (c == 'L') --dirs[0];
            else if (c == 'R') ++dirs[0];
            else ++dirs[1];
        }

        return abs(dirs[0]) + dirs[1];
    }
};