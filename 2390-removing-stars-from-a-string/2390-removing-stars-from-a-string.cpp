class Solution {
public:
    string removeStars(string s) {
        string new_s = "";
        for (const char&c : s){
            if (c == '*'){
                if (!new_s.empty()) new_s.pop_back();
            }
            else new_s.push_back(c);
        }
        return new_s;
    }
};