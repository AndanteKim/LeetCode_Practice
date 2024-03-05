class Solution {
public:
    int minimumLength(string s) {
        int n = s.size(), i = 0, j = n - 1;
        
        while (i < j){
            char prefix = s[i], suffix = s[j];
            if (prefix == suffix){
                while (i <= j && prefix == s[i]) ++i;
                while (i <= j && suffix == s[j]) --j;
            }
            else
                break;
        }
        return j - i + 1;
    }
};