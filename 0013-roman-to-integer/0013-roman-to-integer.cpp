class Solution {
public:
    unordered_map<string, int> values{\
        {"I", 1}, {"V", 5}, {"X", 10}, {"L", 50}, {"C", 100}, {"D", 500}, {"M", 1000},\
        {"IV", 4}, {"IX", 9}, {"XL", 40}, {"XC", 90}, {"CD", 400}, {"CM", 900}
    };
    int romanToInt(string s) {
        int i = 0, total = 0;
        
        while (i < s.size()){
            if (i < s.size() - 1 && values.find(s.substr(i, 2)) != values.end()){
                total += values[s.substr(i, 2)];
                i += 2;
            }
            else{
                total += values[s.substr(i, 1)];
                ++i;
            }
        }
        
        return total;
    }
};