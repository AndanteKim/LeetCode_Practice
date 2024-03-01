class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int zeros = count(s.begin(), s.end(), '0'), n = s.size();
        int ones = n - zeros;
        string ans = "";
        
        if (ones > 1) ans += string(ones - 1, '1');
        ans += string(zeros, '0');
        return ans + '1';
    }
};