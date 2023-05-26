class Solution {
public:
    int appendCharacters(string s, string t) {
        int s_i = 0, t_i = 0, s_len = s.size(), t_len = t.size();
        
        while (s_i < s_len && t_i < t_len){
            if (s[s_i] == t[t_i]){
                ++s_i;
                ++t_i;
            }
            else ++s_i;
        }
        
        return t_len - t_i;
    }
};