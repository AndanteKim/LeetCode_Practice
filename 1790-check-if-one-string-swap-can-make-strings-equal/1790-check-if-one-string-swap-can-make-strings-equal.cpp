class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true;
        unordered_map<char, int> c1, c2;
        
        for(const auto &ch : s1) ++c1[ch];
        for(const auto &ch : s2) ++c2[ch];
        int cnt = 0;
        for (int i = 0; i < s1.size(); ++i){
            cnt += (s1[i] != s2[i]);
            if (cnt > 2) return false;
            if (c1[s1[i]] != c2[s1[i]]) return false;
        }
        return true;
    }
};