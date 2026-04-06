class Solution {
private:
    // Custom hash for pair<int, int>
    struct pairHash {
        size_t operator()(const pair<int, int>& p) const {
            return ((long long)p.first << 32) ^ p.second;
        }
    };

public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<pair<int, int>, pairHash> st;

        for (int i = 0; i < obstacles.size(); ++i) st.insert({obstacles[i][0], obstacles[i][1]});
        vector<pair<int, int>> dirs {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int d = 0, x = 0, y = 0, ans = 0;

        for (int i = 0; i < commands.size(); ++i) {
            if (commands[i] == -1) d = (d + 1) % 4;
            else if (commands[i] == -2) d = (d + 3) % 4;
            else {

                for (int j = 0; j < commands[i]; ++j) {
                    int nx = x + dirs[d].first;
                    int ny = y + dirs[d].second;

                    if (st.count({nx, ny})) break;
                    x = nx;
                    y = ny;
                    
                    ans = max(ans, x * x + y * y);
                }
            } 
        }

        return ans;
    }
};