class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string new_s = "", new_t = "";
        
        for (const char& c: s){
            if (c == '#'){
                if (!new_s.empty()) new_s.pop_back();
            }
            else{
                new_s.push_back(c);
            }
        }
        
        for (const char& c: t){
            if (c == '#') {
                if (!new_t.empty()) new_t.pop_back();
            }
            else{
                new_t.push_back(c);
            }
        }
        
        return new_s == new_t;
    }
};