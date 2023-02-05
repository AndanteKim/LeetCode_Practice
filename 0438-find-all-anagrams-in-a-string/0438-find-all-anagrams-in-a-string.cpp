class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int len_p = p.size(), left = 0;
        vector<int> ans;
        vector<int> p_elems(26, 0), s_elems(26, 0);
        for (const char& c: p) ++p_elems[c - 'a'];
        
        for (int right = 0; right < s.size(); ++right){
            if (s_elems[s[right] - 'a'] < p_elems[s[right] - 'a']) ++s_elems[s[right] - 'a'];
            else{
                while (left < right && s_elems[s[right] - 'a'] >= p_elems[s[right] - 'a']){
                    if (s_elems[s[left] - 'a'] > 0) --s_elems[s[left] - 'a'];
                    ++left;
                }
                
                if (p_elems[s[right] - 'a'] > 0) ++s_elems[s[right] - 'a'];
            }
            if (p_elems == s_elems) ans.push_back(right - len_p + 1);
        }
        return ans;
    }
};