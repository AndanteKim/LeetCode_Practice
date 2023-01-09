class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> counter_s;
        char ans;
        for (const auto &c: s)++counter_s[c];
        
        for (const auto &c: t){
            if (counter_s.find(c) == counter_s.end() || counter_s[c] == 0) {ans = c; break;}
            else --counter_s[c];
        }
        return ans;
    }
};