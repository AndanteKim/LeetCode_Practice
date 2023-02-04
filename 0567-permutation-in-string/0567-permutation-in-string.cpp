class Solution {
    bool matches(vector<int> &s1, vector<int> &s2){
        for (int i = 0; i < 26; ++i) if (s1[i] != s2[i]) return false;
        return true;
    }
    
public:
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.size(), l2 = s2.size();
        if (l1 > l2) return false;
        
        vector<int> dic_s1(26, 0), dic_s2(26, 0);
        
        for (int i = 0; i < l1; ++i) {
            ++dic_s1[s1[i] - 'a'];
            ++dic_s2[s2[i] - 'a'];
        }
        
        for (int i = 0; i < l2 - l1; ++i){
            if (matches(dic_s1, dic_s2)) return true;
            ++dic_s2[s2[i+l1] - 'a'];
            --dic_s2[s2[i] - 'a'];
        }
        
        return matches(dic_s1, dic_s2);
    }
};