class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mapping_s_t, mapping_t_s;
        
        for (int i = 0; i < s.size(); ++i){
            if (mapping_s_t.find(s[i]) == mapping_s_t.end() && mapping_t_s.find(t[i]) == mapping_t_s.end()) {
                mapping_s_t[s[i]] = t[i];
                mapping_t_s[t[i]] = s[i];
            }
            else if (mapping_s_t[s[i]] != t[i] || mapping_t_s[t[i]] != s[i]) return false;
        }
        
        return true;
    }
};