class Solution {
public:
    bool checkIfPangram(string sentence) {
        int seen = 0;
        
        for (const char& curr_char : sentence){
            int mapped_index = curr_char - 'a';
            int curr_bit = 1 << mapped_index;
            seen |= curr_bit;
        }
        
        return seen == (1 << 26) - 1? true : false;
    }
};