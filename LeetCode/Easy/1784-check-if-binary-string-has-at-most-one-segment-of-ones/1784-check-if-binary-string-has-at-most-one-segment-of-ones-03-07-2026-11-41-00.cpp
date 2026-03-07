class Solution {
public:
    bool checkOnesSegment(string s) {
        return !s.contains("01");
    }
};