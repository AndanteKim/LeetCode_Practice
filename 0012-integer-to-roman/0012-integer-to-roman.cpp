class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> values{
            {1, "I"}, {4, "IV"}, {5, "V"},\
            {9, "IX"}, {10, "X"}, {40, "XL"},\
            {50, "L"}, {90, "XC"}, {100, "C"},\
            {400, "CD"}, {500, "D"}, {900, "CM"},\
            {1000, "M"}
        };
        
        int n = values.size() - 1;
        string ans = "";
        
        while (num > 0){
            for (int i = n; i >= 0; --i){
                auto [val, roman] = values[i];
                while (num >= val){
                    ans += roman;
                    num -= val;
                }
            }
        }
        
        return ans;
    }
};