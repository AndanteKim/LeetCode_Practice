class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        int n = s.size(), sections = ceil(n / (double)(2 * numRows - 2));
        int num_cols = sections * (numRows - 1);
        
        vector<vector<char>> matrix(numRows, vector<char>(num_cols, ' '));
        int curr_row = 0, curr_col = 0, curr_string_index = 0;
        
        while (curr_string_index < n){
            // move down
            while (curr_row < numRows && curr_string_index < n){
                matrix[curr_row][curr_col] = s[curr_string_index];
                ++curr_row; ++curr_string_index;
            }        
            
            curr_row -= 2;
            ++curr_col;
            
            // move up
            while (curr_row > 0 && curr_col < num_cols && curr_string_index < n){
                matrix[curr_row][curr_col] = s[curr_string_index];
                --curr_row;
                ++curr_string_index;
                ++curr_col;
            }
        }
        
        string answer = "";
        
        for (const vector<char>& row : matrix){
            for (const char& elem : row) {
                if (elem != ' ') answer += elem;
            }
        }
        
        return answer;
    }
};