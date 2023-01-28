class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> lookup;
        for (const auto& c: s) ++lookup[c];
        int prev = -1;
        for (const auto &[key, val] : lookup){
            if (prev == -1) {
                prev = val;
                continue;
            }
            if (prev != val) return false;
        }
        return true;
    }
};