class Solution {
public:
    bool isIsomorphic(string s, string t) {
        set<char> dic_s(s.begin(), s.end());
        set<char> dic_t(t.begin(), t.end());
        set<pair<char, char>> dic_s_t;
        for (int i = 0; i < s.size(); ++i){
            dic_s_t.insert(make_pair(s[i], t[i]));
        }
        
        return dic_s.size() == dic_t.size() && dic_t.size() == dic_s_t.size()? true : false;
    }
};