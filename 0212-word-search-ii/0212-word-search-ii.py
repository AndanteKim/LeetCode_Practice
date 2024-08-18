class Solution {
private:
    int rows, cols;
    // 4 Directions i.e. up, down, left, right
    vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    struct Trie{
        string word;
        unordered_map<char, Trie*> children;
        Trie(): word(""), children({}){}
    };
    
    void createTrie(string& word, Trie *curr){
        for (char& letter : word){
            if (!curr -> children.count(letter))
                curr -> children[letter] = new Trie();
            curr = curr -> children[letter];
        }
        
        // Store words in Trie
        curr -> word = word; 
    }
    
    void backtrack(int row, int col, Trie *parent, vector<vector<char>>& board, vector<string>& ans){
        char letter = board[row][col];
        Trie *currNode = parent -> children[letter];
        
        // Check if there is any match.
        if (!currNode -> word.empty()){
            ans.push_back(currNode -> word);
            // Prevent duplicate entries
            currNode -> word.clear();
        }
        
        // Mark the current letter before the exploration
        board[row][col] = '#';
        
        // Explore the neighbor cells
        for (auto& [dr, dc] : directions){
            int newR = row + dr, newC = col + dc;
            
            if (newR < 0 || newR >= rows || newC < 0 || newC >= cols)
                continue;
            
            if (!currNode -> children.count(board[newR][newC]))
                continue;
            
            backtrack(newR, newC, currNode, board, ans);
        }
        
        // End of exploration, restore the original letter in the board.
        board[row][col] = letter;
        
        // Optimization: Incrementally remove the leaf nodes.
        if (currNode -> children.empty())
            parent -> children.erase(letter);
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        this -> rows = board.size(), this -> cols = board[0].size();
        Trie *root = new Trie();
        
        // Step 1). Construct the Trie.
        for (string& word: words){
            createTrie(word, root);
        }
        
        vector<string> ans;
        // Step 2). Backtrack starting for each cell in the board
        for (int row = 0; row < rows; ++row){
            for (int col = 0; col < cols; ++col){
                if (root -> children.count(board[row][col]))
                    backtrack(row, col, root, board, ans);
            }
        }
        
        return ans;
    }
};