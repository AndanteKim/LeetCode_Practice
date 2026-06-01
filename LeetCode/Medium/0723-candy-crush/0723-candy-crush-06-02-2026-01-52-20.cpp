class Solution {
private:
    struct pairHash {
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };

    int m, n;

    unordered_set<pair<int, int>, pairHash> find(vector<vector<int>>& board) {
        unordered_set<pair<int, int>, pairHash> crushedSet;

        // Check vertically adjacent candies
        for (int r = 1; r < m - 1; ++r) {
            for (int c = 0; c < n; ++c) {
                if (board[r][c] == 0) continue;

                if (board[r - 1][c] == board[r][c] && board[r][c] == board[r + 1][c]) {
                    crushedSet.insert({r, c});
                    crushedSet.insert({r - 1, c});
                    crushedSet.insert({r + 1, c});
                }
            }
        }

        // Check horizontally adjacent candies
        for (int r = 0; r < m; ++r) {
            for (int c = 1; c < n - 1; ++c) {
                if (board[r][c] == 0) continue;

                if (board[r][c - 1] == board[r][c] && board[r][c] == board[r][c + 1]) {
                    crushedSet.insert({r, c});
                    crushedSet.insert({r, c - 1});
                    crushedSet.insert({r, c + 1});
                }
            }
        }

        return crushedSet;       
    }

    // Set the value of each candies to be crushed as 0
    void crush(vector<vector<int>>& board, unordered_set<pair<int, int>, pairHash>& crushedSet) {
        for (const auto& [r, c] : crushedSet) board[r][c] = 0;
    }

    void drop(vector<vector<int>>& board) {
        for (int c = 0; c < n; ++c) {
            int lowestZero = -1;

            // Iterate over the column
            for (int r = m - 1; r >= 0; --r) {
                if (board[r][c] == 0) lowestZero = max(lowestZero, r);

                // Swap current non-zero candy with the lowest zero.
                else if (lowestZero >= 0) swap(board[r][c], board[lowestZero--][c]);
            }
        }
    }

public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        this -> m = board.size(), this -> n = board[0].size();

        // Continue with the 3 steps until we can no longest find any crushable candies.
        unordered_set<pair<int, int>, pairHash> crushedSet = find(board);

        while (!crushedSet.empty()) {
            crush(board, crushedSet);
            drop(board);
            crushedSet = find(board);
        }
        
        return board;
    }
};