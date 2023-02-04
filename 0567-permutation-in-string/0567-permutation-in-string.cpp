class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.size(), l2 = s2.size();
        
        if (l1 > l2) return false;
        
        unordered_map<char, int> dic_s1;
        for (const char&c : s1) ++dic_s1[c];
        for (int i = 0; i <= l2 - l1; ++i){
            unordered_map<char, int> dic_s2;
            for (int j = 0; j < l1; ++j) ++dic_s2[s2[i + j]];
            
            if (dic_s1 == dic_s2) return true;
        }
        
        return false;
    }
};