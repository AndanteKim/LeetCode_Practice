class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int len_p = p.size(), left = 0;
        vector<int> ans;
        unordered_map<char, int> p_elems, s_elems;
        for (const char& c: p) ++p_elems[c];
        
        for (int right = 0; right < s.size(); ++right){
            if (s_elems[s[right]] < p_elems[s[right]]) ++s_elems[s[right]];
            else{
                while (left < right && s_elems[s[right]] >= p_elems[s[right]]){
                    if (s_elems[s[left]] > 0) --s_elems[s[left]];
                    ++left;
                }
                
                if (p_elems[s[right]] > 0) ++s_elems[s[right]];
            }
            if (p_elems == s_elems) ans.push_back(right - len_p + 1);
        }
        return ans;
    }
};