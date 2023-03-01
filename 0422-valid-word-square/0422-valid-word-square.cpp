class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int cols = 0, rows = words.size();
        vector<string> new_words;
        for (string& word: words) cols = max(cols, (int)word.size());
        
        if (cols != words[0].size() || cols != rows) return false;
        
        for (int col = 0; col < cols; ++col){
            string new_word = "";
            for (int row = 0; row < rows; ++row){
                if (col < words[row].size()) new_word += words[row][col];
            }
            new_words.push_back(new_word);
        }
        
        return words == new_words;
    }
};