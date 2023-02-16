class Solution {
public:
    string build(string &s){
        string new_s = "";
        for (const char&c : s){
            if (c != '#') new_s.push_back(c);
            else if (!new_s.empty()) new_s.pop_back();
        }
        
        return new_s;
    }
    
    bool backspaceCompare(string s, string t) {
        return build(s) == build(t);
    }
};