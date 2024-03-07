class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> digits{
            {1000, "M"}, {900, "CM"}, {500, "D"},\
            {400, "CD"}, {100, "C"}, {90, "XC"},\
            {50, "L"}, {40, "XL"}, {10, "X"},\
            {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };
        
        string ans = "";
        
        // Loop through each symbol
        for (auto& [val, symbol]:digits){
            // We don't want to continue looping if we're done.
            if (num == 0) break;
            
            int count = num / val;
            num %= val;
            
            // Append "count" copies of "symbol" to roman_digits
            for (int i = 0; i < count; ++i)
                ans.append(symbol);
        }
        
        return ans;
    }
};