namespace{
    const std::array<std::pair<int, int>, 8> neighbours {{
        {1, 1}, {0, 1}, {1, 0}, {-1, 1}, {1, -1},\
        {0, -1}, {-1, 0}, {-1, -1}\
    }};

    struct square {
        int g_score{INT_MAX};
        int f_score{INT_MAX};
        bool in_open_set{false};
    };

    using square_iterator = std::vector<square>::iterator;
    auto lowest_fscore_cmp = [](const square_iterator lhs, const square_iterator rhs){
        return lhs -> f_score > rhs -> f_score;
    };
    
    using p_queue = std::priority_queue<square_iterator, std::vector<square_iterator>,\
                                    decltype(lowest_fscore_cmp)>;
}

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n_rows = grid.size();
        if (n_rows == 0) return -1;
        int n_cols = grid[0].size();
        if (n_cols == 0 || grid[0][0] == 1 || grid[n_rows - 1][n_cols - 1] == 1) return -1;
        
        auto h = [n_rows, n_cols] (int y, int x){
            auto dx = (n_cols - 1) - x;
            auto dy = (n_rows - 1) - y;
            return max(dx, dy);
        };
        
        vector<square> squares(n_rows * n_cols);
        auto getSquare = [&squares, n_cols](int y, int x){
            return squares.begin() + (y * n_cols + x);
        };
        
        auto getXY = [&squares, n_cols](square_iterator it){
            auto idx = std::distance(squares.begin(), it);
            return make_pair<int, int> (idx / n_cols, idx % n_cols);
        };
        
        auto start = getSquare(0, 0);
        start -> g_score = 1;
        start -> f_score = h(0, 0);
        auto dest = getSquare(n_rows - 1, n_cols - 1);
        p_queue OpenSet(lowest_fscore_cmp);
        start -> in_open_set = true;
        OpenSet.push(start);
        
        while (!OpenSet.empty()){
            auto current = OpenSet.top();
            if (current == dest) return dest -> g_score;
            OpenSet.pop();
            if (!current -> in_open_set) continue;
            current -> in_open_set = false;
            
            auto [curr_y, curr_x] = getXY(current);
            
            for (const auto &n : neighbours){
                auto y = curr_y + n.first;
                auto x = curr_x + n.second;
                if (y >= 0 && y < n_rows && x >= 0 && x < n_cols && grid[y][x] == 0){
                    auto neighbour = getSquare(y, x);
                    auto tentative_g_score = current -> g_score + 1;
                    if (tentative_g_score < neighbour -> g_score){
                        neighbour -> g_score = tentative_g_score;
                        neighbour -> f_score = neighbour -> g_score + h(y, x);
                        neighbour -> in_open_set = true;
                        OpenSet.push(neighbour);
                    }
                }
            }
        }
        return -1;
    }
};