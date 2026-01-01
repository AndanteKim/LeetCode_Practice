class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;

        for (int i = digits.size() - 1; i >= 0; --i) {
            int digit = digits[i] + carry;
            digits[i] = digit % 10;
            carry = digit / 10;
        }

        if (carry) digits.insert(digits.begin(), carry); 

        return digits;
    }
};