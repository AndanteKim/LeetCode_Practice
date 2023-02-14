class Solution {
public:
    string addBinary(string a, string b) {
        bitset<128> x(a);
        bitset<128> y(b);
        
        while (y.any()){
            bitset<128> answer = x ^ y;
            bitset<128> carry = (x & y) << 1;
            x = answer;
            y = carry;
        }
        
        string s = x.to_string();
        int i = 0;
        while (s[i] == '0') ++i;
        s = s.substr(i);
        return s == ""? "0" : s;
    }
};