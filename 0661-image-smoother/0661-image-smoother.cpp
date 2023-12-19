class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<pair<int, int>> directions{{0, 0}, {-1, 1}, {0, 1},\
        {1, 1}, {1, 0}, {1, -1},\
        {0, -1}, {-1, -1}, {-1, 0}
                                         };
        int m = img.size(), n = img[0].size();
        vector filtered(m, vector<int>(n));
        
        for (int y = 0; y < m; ++y){
            for (int x = 0; x < n; ++x){
                int total = 0, cells = 0;
                for (auto& [dy, dx] : directions){
                    if (0 <= y + dy && y + dy < m && 0 <= x + dx && x + dx < n){
                        total += img[y + dy][x + dx];
                        ++cells;
                    }
                }
                filtered[y][x] = total / cells;
            }
        }
        
        return filtered;
    }
};