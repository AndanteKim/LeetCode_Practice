class Solution {
public:
    string largestGoodInteger(string num) {
        char maxDigit = '\0';
        
        for (int i = 0; i < num.size(); ++i)
            if (num[i] == num[i + 1] && num[i + 1] == num[i + 2])
                maxDigit = max(num[i], maxDigit);
        
        return maxDigit == '\0'? "":string(3, maxDigit);
    }
};