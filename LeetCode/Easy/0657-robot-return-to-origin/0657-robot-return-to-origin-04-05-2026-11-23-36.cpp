class Solution {
public:
    bool judgeCircle(string moves) {
        pair<int, int> pos = {0, 0};
        unordered_map<char, pair<int, int>> dirs {{'U', {0, 1}}, {'D', {0, -1}}, {'L', {-1, 0}}, {'R', {1, 0}}};

        for (const char& mv : moves) {
            const auto [dx, dy] = dirs[mv];
            pos.first += dx;
            pos.second += dy;
        }

        return pos == pair<int, int>{0, 0};
    }
};