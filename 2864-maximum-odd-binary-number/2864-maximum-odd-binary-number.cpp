class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        sort(s.begin(), s.end());
        int secondLast = s.size() - 2;
        
        for (int i = 0; i < s.size() >> 1; ++i){
            swap(s[i], s[secondLast - i]);
        }
        
        return s;
    }
};