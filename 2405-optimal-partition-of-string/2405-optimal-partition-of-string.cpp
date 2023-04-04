class Solution {
public:
    int partitionString(string s) {
        int ans = 1, chars_bitmask = 0;
        
        for(const char&c : s){
            int set_bit = 1 << c - 97;
            if (chars_bitmask & set_bit){
                ++ans;
                chars_bitmask = 0;
            }
            chars_bitmask |= set_bit;
        }
        
        return ans;
    }
};