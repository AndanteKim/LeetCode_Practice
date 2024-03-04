class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        // Get n
        int n = s.size(), left = 0, right = n - 1;
        
        while (left <= right){
            // Increment left if equals '1'.
            if (s[left] == '1') ++left;
            
            // Decrement right if equals '0'.
            if (s[right] == '0') --right;
            
            // Swap if neither pointer can be iterated
            if (left <= right && s[left] == '0' && s[right] == '1'){
                swap(s[left], s[right]);
            }
        }
        
        // Swap rightmost 1 bit to the end
        swap(s[left - 1], s[n - 1]);
        return s;
    }
};