class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_set<int> s;
        unordered_map<int, int> m;
        for (int n : arr) ++m[n];
        for (auto&[key, freq] : m) s.insert(freq);
        return s.size() == m.size();
    }
};