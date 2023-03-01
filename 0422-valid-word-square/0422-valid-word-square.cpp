class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        for (int word_num = 0; word_num < words.size(); ++word_num){
            for (int char_pos = 0; char_pos < words[word_num].size(); ++char_pos){
                if (char_pos >= words.size() || word_num >= words[char_pos].size() ||\
                   words[word_num][char_pos] != words[char_pos][word_num]) return false;
            }
        }
        
        return true;
    }
};