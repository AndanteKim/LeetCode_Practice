class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text2.size() < text1.size()) swap(text1, text2);
        
        vector<int> previous(text1.size() + 1, 0), current(text1.size() + 1, 0);
        for (int col = text2.size() - 1; col >= 0; --col){
            for (int row = text1.size() - 1; row >= 0; --row){
                if (text2[col] == text1[row]) current[row] = 1 + previous[row + 1];
                else current[row] = max(previous[row], current[row + 1]);
            }
            swap(previous, current);
        }
        return previous[0];
    }
};