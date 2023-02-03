class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        
        string answer = "";
        int n = s.size(), chars_in_section = 2 * (numRows - 1);
        
        for (int curr_row = 0; curr_row < numRows; ++curr_row){
            int index = curr_row;
            
            while(index < n){
                answer += s[index];
                
                if (curr_row != 0 && curr_row != numRows - 1){
                    int chars_in_between = chars_in_section - (2 * curr_row);
                    int second_index = index + chars_in_between;
                    if (second_index < n) answer += s[second_index];
                }
                index += chars_in_section;
            }
        }
        
        return answer;
    }
};