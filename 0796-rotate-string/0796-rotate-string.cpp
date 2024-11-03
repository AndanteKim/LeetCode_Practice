class Solution {
public:
    bool rotateString(string s, string goal) {
        goal += goal;
        
        return (s.size() == (goal.size() >> 1)) && (goal.find(s) != string::npos);
    }
};