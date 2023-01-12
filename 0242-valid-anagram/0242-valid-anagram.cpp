class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> counter_s, counter_t;
        for(const auto &c:s) ++counter_s[c];
        for(const auto &c:t) ++counter_t[c];
        return counter_s == counter_t;
    }
};