struct hashFunction{
    size_t operator()(const pair<int, int>& x) const{
        return x.first ^ x.second;
    }
};

class Solution {
private:
    int m, n;
    unordered_set<pair<int, int>, hashFunction> find(vector<vector<int>>& board){
        unordered_set<pair<int, int>, hashFunction> crushedSet;
        // Check vertically adjacent candies
        for (int r = 1; r < m - 1; ++r){
            for (int c = 0; c < n; ++c){
                if (!board[r][c]) continue;
                else if (board[r - 1][c] == board[r][c] && board[r][c] == board[r + 1][c]){
                    crushedSet.insert(make_pair(r - 1, c));
                    crushedSet.insert(make_pair(r, c));
                    crushedSet.insert(make_pair(r + 1, c));
                }
            }
        }
        
        // Check horizontally adjacent candies
        for (int r = 0; r < m; ++r){
            for (int c = 1; c < n - 1; ++c){
                if (!board[r][c]) continue;
                else if (board[r][c - 1] == board[r][c] && board[r][c] == board[r][c + 1]){
                    crushedSet.insert(make_pair(r, c - 1));
                    crushedSet.insert(make_pair(r, c));
                    crushedSet.insert(make_pair(r, c + 1));
                }
            }
        }
        
        return crushedSet;
    }
    
    void crush(vector<vector<int>>& board, unordered_set<pair<int, int>, hashFunction>& crushedSet){
        for (const auto& [r, c] : crushedSet){
            board[r][c] = 0;
        }
    }
    
    void drop(vector<vector<int>>& board){
        for (int c = 0; c < n; ++c){
            int lowestZero = -1;
            
            // Iterate over each column
            for (int r = m - 1; r >= 0; --r){
                if (!board[r][c]) lowestZero = max(lowestZero, r);
                else if (lowestZero >= 0) {
                    swap(board[r][c], board[lowestZero][c]);
                    --lowestZero;
                }
            }
        }
    }
    
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        m = board.size(), n = board[0].size();
        unordered_set<pair<int, int>, hashFunction> crushedSet = find(board);
        while(!crushedSet.empty()){
            crush(board, crushedSet);
            drop(board);
            crushedSet = find(board);
        }
        
        return board;
    }
};