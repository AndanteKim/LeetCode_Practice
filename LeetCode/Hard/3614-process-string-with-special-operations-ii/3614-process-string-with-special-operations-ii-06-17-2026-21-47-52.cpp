class Solution {
public:
    char processStr(string s, long long k) {
        long long length = 0;

        for (const char& c : s) {
            if (c == '*') {
                if (length) --length;
            }
            else if (c == '#') length *= 2;
            else if (c == '%') continue;
            else ++length;
        }

        if (k + 1 > length) return '.';

        reverse(s.begin(), s.end());
        for (const char& c : s) {
            if (c == '*') ++length;
            else if (c == '#') {
                if (k + 1 > ((length + 1) >> 1)) {
                    k -= (length >> 1);
                }
                length = ((length + 1) >> 1);
            }
            else if (c == '%') {
                k = length - k - 1;
            }
            else {
                if ((k + 1) == length) return c;
                --length; 
            }
        }

        return '.';
    }
};