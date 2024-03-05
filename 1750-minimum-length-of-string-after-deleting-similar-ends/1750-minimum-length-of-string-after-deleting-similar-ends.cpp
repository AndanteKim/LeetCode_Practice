class Solution {
public:
    int minimumLength(string s) {
        int end = s.size() - 1, begin = 0;
        
        // Delete similar ends until the end differ or they meet in the middle
        while (begin < end && s[begin] == s[end]){
            char c = s[begin];
            // Delete consecutive occurrences of c from prefix
            while (begin <= end && s[begin] == c)
                ++begin;
            
            // Delete consecutive occurrences of c from suffix
            while (end > begin && s[end] == c)
                --end;
            
        }
        
        // Return the number of remain characters
        return end - begin + 1;
    }
};