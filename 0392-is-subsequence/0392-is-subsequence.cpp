class Solution {
public:
    bool isSubsequence(string s, string t) {
        int LEFT_BOUND = s.size(), RIGHT_BOUND = t.size(), i = 0, j = 0;
        
        while (i < LEFT_BOUND and j < RIGHT_BOUND){
            if (s[i] == t[j]) ++i;
            ++j;
        }
        return i == LEFT_BOUND? true : false; 
    }
};