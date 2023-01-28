class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> lookup;
        set<int> values;
        for (const auto& c: s) ++lookup[c];
        for (const auto &[key, val] : lookup){
            values.insert(val);
        }
        return values.size() == 1 ? true:false;
    }
};